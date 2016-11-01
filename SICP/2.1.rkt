#lang Scheme


(define (gcd a b)
  (if (= b 0)
      a
      (gcd b (remainder a b))))

(define (add-rat x y)
  (make-rat (+ (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (sub-rat x y)
  (make-rat (- (* (numer x) (denom y))
               (* (numer y) (denom x)))
            (* (denom x) (denom y))))

(define (mul-rat x y)
  (make-rat (* (numer x) (numer y))
            (* (denom x) (denom y))))

(define (div-rat x y)
  (make-rat (* (numer x) (denom y))
            (* (denom x) (numer y))))

(define (equal-rat? x y)
  (= (* (numer x) (denom y))
     (* (numer y) (denom x))))

(define (make-rat0 n d) (cons n d))
(define (numer x) (car x))
(define (denom x) (cdr x))

(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

(define (make-rat n d)
  (let ((g (gcd n d)))
    (cons (/ n g) (/ d g))
    ))

(define (make-rat1 n d)
  (let ((g (gcd (abs n) (abs d))))
    (cond ((and (> n 0) (< d 0)) (cons (- (/ n g)) (- (/ d g))))
          ((and (< n 0) (< d 0)) (cons (/ n g) (- (/ d g))))
          (else (cons (/ n g) (/ d g)))
          ))
  )

(define a (make-rat1 -1 2))
(define a2 (make-rat1 1 -3))
(define a3 (make-rat1 1 3))
(define a4 (make-rat1 -1 -3))
(define a5 (cons -1 -2))

(define (make-segment x1 x2 y1 y2)
  (cons (cons x1 x2) (cons y1 y2)))
(define (start-segment x) (car x))
(define (end-segment x) (cdr x))
(define (x-point p) (car p))
(define (y-point p) (cdr p))
(define (print-point p)
  (newline)
  (display "(")
  (display (x-point p))
  (display ",")
  (display (y-point p))
  (display ")")
  )
(define (midpoint-segment seg)
  (let ((x1 (car (start-segment seg)))
        (x2 (cdr (start-segment seg)))
        (y1 (car (end-segment seg)))
        (y2 (cdr (end-segment seg))))
  (cons (/ (+ x1 y1) 2) (/ (+ x2 y2) 2))))
(define s (make-segment 12 3 20 50))

(define (retangle x1 y1 length width)
  (cons (cons x1 y1)
        (cons length width)))

(define (perimeter ret)
  (* (+ (x-point (end-segment ret)) (y-point (end-segment ret))) 2))

(define (area ret)
  (* (x-point (end-segment ret)) (y-point (end-segment ret))))

(define r1 (retangle 0 0 20 30))

(define (add-interval x y)
  (make-interval (+ (lower-bound x) (lower-bound y))
                 (+ (upper-bound x) (upper-bound y)))
  )

(define (mul-interval x y)
  (let ))