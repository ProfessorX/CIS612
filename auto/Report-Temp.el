(TeX-add-style-hook "Report-Temp"
 (lambda ()
    (LaTeX-add-bibliographies
     "IEEEabrv"
     "Reference")
    (LaTeX-add-environments
     "definition")
    (LaTeX-add-labels
     "sec:introduction"
     "sec:publ-key-crypt"
     "sec:rsa-cryptosystem"
     "sec:el-gamal-crypt"
     "sec:diff-hellm-probl"
     "sec:diff-hellm-probl-1"
     "sec:diff-hellm-probl-2"
     "sec:disctr-logar-probl"
     "def:Generalized-DLP"
     "eq:discrete-1"
     "sec:exhaustive-search"
     "sec:baby-step-giant"
     "sec:poll-rho-algor-1"
     "eq:pollard-1"
     "eq:pollard-2"
     "eq:pollard-3"
     "eq:pollard-4"
     "fig:pollard-rho-algo"
     "sec:pholig-hellman-algo"
     "fig:pholig-hellman-algo"
     "eq:Pholig-hellman-algo-cc"
     "sec:qquad-index-calculus"
     "eq:index-calculus-algo-1"
     "eq:index-calculus-algo-2"
     "eq:index-calculus-algo-3"
     "fig:index-calculus-algo-in-cyclic"
     "fig:basic-elgamal-encryption"
     "fig:basic-elgamal-public-key-encry-algo"
     "sec:implementation"
     "eq:diffie-1"
     "eq:diffie-2"
     "fig:diffie-key-agreement"
     "fig:algo-baby-step-giant-step")
    (TeX-run-style-hooks
     "hyperref"
     "url"
     "stfloats"
     "fixltx2e"
     "font=footnotesize"
     "subfig"
     "textfont=sf"
     "labelfont=sf"
     "font=normalsize"
     "caption=false"
     "eqparbox"
     "mdwtab"
     "mdwmath"
     "array"
     "algorithmic"
     "amsmath"
     "cmex10"
     "dvips"
     "graphicx"
     "pdftex"
     ""
     "cite"
     "nocompress"
     "latex2e"
     "IEEEtran12"
     "IEEEtran"
     "compsoc"
     "journal"
     "12pt")))

