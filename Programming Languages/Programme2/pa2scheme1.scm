(define (inv_list lst)
  (cond ((not (null? lst))
    (if (list? lst)
      (append (inv_list (cdr lst)) (list (car lst)))
      (list lst)))
  (else '())))

(define (palindrome list1)  ;function name: palindrome
  (append list1 (inv_list list1))
)
(palindrome (list 'a 'b 'c) )