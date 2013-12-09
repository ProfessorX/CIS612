(TeX-add-style-hook "Presentation"
 (lambda ()
    (LaTeX-add-bibliographies
     "Ref")
    (TeX-run-style-hooks
     "algorithmic"
     "amssymb"
     "amsmath"
     ""
     "latex2e"
     "beamer10"
     "beamer"
     "hyperref=true")))

