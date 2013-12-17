(TeX-add-style-hook "InfoSec-HW3"
 (lambda ()
    (LaTeX-add-labels
     "sec:authentication"
     "sec:que-7.9.5"
     "sec:que-7.9.5-2:algo:crack-passwords-1")
    (TeX-run-style-hooks
     "hyperref"
     "algorithmic"
     "algorithm"
     "amssymb"
     "amsmath"
     "latex2e"
     "art10"
     "article"
     "")))

