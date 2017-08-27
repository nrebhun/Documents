#lang racket
[define (rel numA numB)
   (cond [(< numA numB) display -1]
         [(= numA numB) display 0]
         [(> numA numB) display 1]
         )
  ]

[define (get-Element index list)
  (cond [(null? list) display (not (null? list))] 
        [(> index 1) (get-Element (- index 1) (cdr list))]
        [(= index 1) display (car list)]
        )
  ]

[define (get-Element2 index list)
  (cond [(> index 1) (get-Element (- index 1) (cdr list))]
        [(= index 1) display (car list)]
        )
  display list
  ]