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
     "sec:samples"
     "sec:acknowledgment")
    (TeX-run-style-hooks
     "hyperref"
     "graphicx"
     "amssymb"
     "amsmath"
     ""
     "latex2e"
     "art12"
     "article"
     "12pt")))

