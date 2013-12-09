(TeX-add-style-hook "Documentation"
 (lambda ()
    (LaTeX-add-bibliographies
     "Ref")
    (LaTeX-add-environments
     "Definition")
    (LaTeX-add-labels
     "sec:introduction"
     "sec:implementation"
     "sec:data-structure"
     "sec:examples"
     "sec:changelog"
     "sec:acknowledgment")
    (TeX-run-style-hooks
     "hyperref"
     "fancyvrb"
     "graphicx"
     "amssymb"
     "amsmath"
     ""
     "latex2e"
     "art12"
     "article"
     "12pt")))

