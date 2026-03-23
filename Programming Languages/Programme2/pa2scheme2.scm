(define (dbl_atm atm lst) 
  (cond ((not (null? lst))
    (cond ((list? lst)
      (if (list? (car lst))
        (list (append (dbl_atm atm (car lst)) (dbl_atm atm (cdr lst))))
        (append (dbl_atm atm (car lst)) (dbl_atm atm (cdr lst)))))
      (else (cond ((equal? atm lst)
        (append (list atm) (list atm)))
        (else (list lst))))))
    (else '())))


(dbl_atm 'a '(a (b c a (a d))))
