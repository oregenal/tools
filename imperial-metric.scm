(define (far->cel x)
  (exact->inexact (* 5/9 (- x 32))))

(define (cel->far x)
  (exact->inexact (+ (/ x 5/9) 32)))
