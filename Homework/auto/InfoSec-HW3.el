(TeX-add-style-hook "InfoSec-HW3"
 (lambda ()
    (LaTeX-add-bibliographies
     "HW3-Ref")
    (LaTeX-add-labels
     "sec:authentication"
     "sec:que-7.9.5"
     "sec:que-7.9.5-2:algo:crack-passwords-1"
     "sec:que-7.9.5-3:algo:crack-passwords-2"
     "sec:que-7.9.6"
     "sec:que-7.9.7"
     "sec:que-7.9.10"
     "sec:que-7.9.19"
     "fig:toy-birthday-attack"
     "sec:que-7.9.20"
     "fig:toy-birthday-attack-1"
     "sec:que-7.9.37")
    (TeX-run-style-hooks
     "hyperref"
     "graphicx"
     "algorithmic"
     "algorithm"
     "amssymb"
     "amsmath"
     "latex2e"
     "art10"
     "article"
     "")))

