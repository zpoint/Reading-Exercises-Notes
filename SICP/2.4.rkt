#lang Scheme
(define (cons a b)
  (define (2a a)
    (if(= a 0)
       1
       (* 2 (2a (- a 1)))))
  (define (3b b result)
    (if (= b 0)
        result
        (3b (- b 1) (* result 3))))
    (define (dispatch m)
      (cond ((= m 0) (2a a))
            ((= m 1) (3b b 1))
            (else (error "Argument not 0 or 1 --- CONS" m))
            ))
  dispatch
  )

(define (car z) (z 0))
(define (cdr z) (z 1))

(define a (cons 3 4))

(define zero (lambda (f) (lambda (x) x)))
(define (add-1 n)
  (lambda (f) (lambda (x) (f ((n f) x))))
  )



