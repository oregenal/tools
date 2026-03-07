(import utf8)

(define qwerty '(#\q #\w #\e #\r #\t #\y #\u #\i #\o #\p #\[ #\] #\a #\s #\d #\f #\g #\h #\j #\k #\l #\; #\' #\z #\x #\c #\v #\b #\n #\m #\, #\. #\/))

(define icyken '(#\й #\ц #\у #\к #\е #\н #\г #\ш #\щ #\з #\х #\ъ #\ф #\ы #\в #\а #\п #\р #\о #\л #\д #\ж #\э #\я #\ч #\с #\м #\и #\т #\ь #\б #\ю #\.))

(define ass-list '((#\/ . #\.) (#\. . #\ю) (#\, . #\б) (#\m . #\ь) (#\n . #\т) (#\b . #\и) (#\v . #\м) (#\c . #\с) (#\x . #\ч) (#\z . #\я) (#\' . #\э) (#\; . #\ж) (#\l . #\д) (#\k . #\л) (#\j . #\о) (#\h . #\р) (#\g . #\п) (#\f . #\а) (#\d . #\в) (#\s . #\ы) (#\a . #\ф) (#\] . #\ъ) (#\[ . #\х) (#\p . #\з) (#\o . #\щ) (#\i . #\ш) (#\u . #\г) (#\y . #\н) (#\t . #\е) (#\r . #\к) (#\e . #\у) (#\w . #\ц) (#\q . #\й)))

(define (show-char lst)
  (for-each (lambda (c) (write c)) lst)
  (newline))

(define (find c lst)
  (cond 
    ((null? lst) 'NoSuchElement) 
    ((eq? c (car lst)) c) 
    (else (find c (cdr lst)))))

(define (ass-list-make lst1 lst2 ass-list)
  (cond
    ((null? lst1) (write ass-list) (newline))
    (else
      (set! ass-list (cons (cons (car lst1) (car lst2)) ass-list))
      (ass-list-make (cdr lst1) (cdr lst2) ass-list))))

(define (transl c)
  (cdr (assq c ass-list)))

(define (trans-it c)
  (let loop ((lst ass-list))
    (cond
      ((null? lst) 'NoSuchChar)
      ((eq? (caar lst) c) (cdar lst))
      ((eq? (cdar lst) c) (caar lst))
      (else (loop (cdr lst))))))

(define (do-it port)
  (let ((c (read-char port)))
    (cond
      ((eof-object? c) #t)
      (else (let ((ch (trans-it c)))
              (cond 
                ((eq? ch 'NoSuchChar) (write-char c) (do-it port))
                (else (write-char ch) (do-it port))))))))

(do-it (current-input-port))
