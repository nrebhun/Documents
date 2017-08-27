#lang racket
; Begin Binomial Coefficient Function
[define (factorial num result)
  (cond [(> num 1) (factorial (- num 1) (* result num))]
        [(<= num 1) (display result)]
        )
  ]

[define (fac num)
  (factorial num 1)
  ]

[define (binomialCoefficient varN varK)
  (/ (fac varN) (* (fac varK)(fac (- varN varK))))
  ]
[define (biCo varN varK)
  (cond [(< varN varK) (display "First number should be larger than second number.")]
        [(< varN 1) (display "First number must be integer greater than 0")]
        [(< varK 1) (display "Second number must be integer greater than 0")]
        (binomialCoefficient varN varK)
        )
  ]
; End Binary Coefficient Function

; Begin Modulus Function
[define (negMod varA varB)
  (cond [(> varB 0) (negMod varA (* varB -1))]
        [(< varA varB) (negMod (- varA varB) varB)]
        [(> varA varB) display varA]
        [(= varA varB) display 0]
        )
  ]

[define (mod varA varB)
  (cond [(negative? varA) (negMod varA varB)]
       [(negative? varB) (negMod varA varB)]
       [(> varA varB) (mod (- varA varB) varB)]
       [(< varA varB) (display varA)]
       [(= varA varB) (display 0)]
       )
  ]
; End Modulus Function

; Begin Binary - to - Decimal Function 
[define (b2dConverter bNum dNum index)
  (cond [(zero? bNum) (display dNum)]
       [(>= bNum (expt 10 index))  (b2dConverter (- bNum (expt 10 index)) (+ dNum (expt 2 index)) (- index 1))]
       [(<  bNum (expt 10 index))  (b2dConverter bNum dNum (- index 1))]
       )
  ]

[define (b2d num) (b2dConverter num 0 100)]  ; initialization of the b2d converter
; End Binary - to - Decimal Function

; Begin AddBinary Function
[define (bCalc index result binaryList)
  (cond [(< 0 index) (bCalc (- index 1) (+ result (b2d (first binaryList))) (cdr binaryList))]
        [(zero? index) (display result)]
        )
  ]
[define (addBinary binaryList)
  (bCalc (length binaryList) 0 binaryList)
  ]
; End AddBinary Function

; Begin Minimum of List Function
[define (minimumOfList minNum intList)
  (cond [(> 1 (length intList)) (display minNum)]
        [(> minNum (first intList)) (minimumOfList (first intList) (cdr intList))]
        [(<= minNum (first intList)) (minimumOfList minNum (cdr intList))]
        )
  ]
         
[define (min intList)
  (cond [(= (length intList) 0) intList]
        [(minimumOfList (first intList) intList)]
        )
  ]
; End Minimum of List Function

; Begin Atom Removal Function
[define (myRemove atm list)
  (cond [(equal? list (remove atm list)) list]
        [(myRemove atm (remove atm list))]
        )
  ]
; End Atom Removal Function

; Begin Selection Sort
[define (removeFirstInstance atm list)
  (cond [(not (equal? (length list) (length (remove atm list)))) (remove atm list)]
        )
  ]

[define (selectionSort intList sortedList)
  (cond [(> (length intList) 0) (selectionSort (removeFirstInstance (last (flatten (append sortedList (min intList)))) intList) (flatten (append sortedList (min intList))))]
        [(<= (length intList) 0) display sortedList]
        )
  ]

[define (selSort intList)
  (selectionSort intList '())
  ]
; End Selection Sort