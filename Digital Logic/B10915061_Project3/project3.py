import os

def read_kiss_file(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
    return lines

def generate_dot_file(kiss_lines, dot_filename):
    with open(dot_filename, 'w') as file:
        file.write('digraph STG {\n')
        file.write('    rankdir=LR;\n')
        file.write('    INIT [shape=point];\n')
        states = set()
        for line in kiss_lines:
            if line.startswith('.'):
                continue
            parts = line.split()
            if len(parts) == 4:
                states.add(parts[1])
                states.add(parts[2])
                file.write(f'    {parts[1]} -> {parts[2]} [label="{parts[0]}/{parts[3]}"];\n')
        for state in states:
            file.write(f'    {state} [label="{state}"];\n')
        file.write('    INIT -> a;\n')
        file.write('}\n')

def main():
    input_kiss = 'input.kiss'
    output_dot = 'output.dot'
    output_png = 'output.png'

    kiss_lines = read_kiss_file(input_kiss)
    generate_dot_file(kiss_lines, output_dot)

    # 使用Graphviz將DOT文件轉換為PNG圖像
    os.system(f'dot -Tpng {output_dot} -o {output_png}')

if __name__ == "__main__":
    # 創建 input.kiss 文件
    kiss_example = """
.start_kiss
.i 1
.o 1
.p 14
.s 7
.r a
0 a a
0 1 a b
0 0 b c
0 1 b d
0 0 c a
0 1 c d
0 0 d e
0 1 d f
1 0 e a
0 1 e f
1 0 f g
0 1 f f
1 0 g a
0 1 g f
1
.end_kiss
"""
    with open('input.kiss', 'w') as f:
        f.write(kiss_example)
    
    main()

    # 讀取並打印 output.dot 文件的內容
    with open('output.dot', 'r') as f:
        output_dot_content = f.read()

    print(output_dot_content)

    # 提示用戶生成的PNG圖像文件
    print("STG圖像已生成，文件名為output.png")
