(TeX-add-style-hook "InfoSecReport"
 (lambda ()
    (LaTeX-add-bibliographies
     "IEEEabrv"
     "Reference")
    (LaTeX-add-environments
     "definition")
    (LaTeX-add-labels
     "sec:introduction"
     "fig:intro-process-of-symmetric"
     "fig:intro-process-of-asymetric"
     "sec:rsa-cryptosystem"
     "sec:rsa-background"
     "sec:rsa-details"
     "sec:known-attacks-rsa"
     "sec:qquad-fact-large"
     "sec:qquad-Elementary-attacks"
     "sec:qquad-low-private"
     "sec:qquad-low-public"
     "eq:low-public-expo-1"
     "eq:low-public-expo-2"
     "sec:qquad-Implementation-attacks"
     "sec:el-gamal-crypt"
     "sec:diff-hellm-probl"
     "sec:diff-hellm-probl-1"
     "sec:diff-hellm-probl-2"
     "eq:diffie-1"
     "eq:diffie-2"
     "fig:diffie-key-agreement"
     "sec:disctr-logar-probl"
     "def:Generalized-DLP"
     "eq:discrete-1"
     "sec:exhaustive-search"
     "sec:baby-step-giant"
     "fig:algo-baby-step-giant-step"
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
     "eq:basic-elgamal-encry-algo"
     "sec:implementation")
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

