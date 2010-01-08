# Directories
IMG=images
TMP=temp

# In-file and out-file
ifeq ($(IN),)
	IN=main
endif
ifeq ($(OUT),)
	OUT=Correction
endif

# Compilators
TEX=latex
BTEX=bibtex
INDEX=makeindex
GLOSS=makeglos
DVIPS=dvips
PS2PDF=ps2pdf

# Compilators options
TEXOPT=-shell-escape -output-format=dvi -file-line-error -interaction nonstopmode -output-directory=$(TMP)
BTEXOPT=
INDEXOPT=
GLOSSOPT=-m
DVIPSOPT=-R0
PS2PDFOPT=

# Others
UNAME=$(shell uname)
MKIMG='PNG=\044(wildcard *.png)\nEPS=\044(PNG:.png=.eps)\n\nall: \044(EPS)\n\t@echo --- IMAGES TRAITÉES ---\n\n%.eps: %.png\n\tconvert \044< eps:->\044@\n\nclean:\n\t@echo --- RIEN À ENLEVER ---\n\nproper:\n\t@rm -f *.eps'

.PHONY: final draft pdf ps dvi img clean proper

all: draft

# To create the final document with:
#   - the images
#   - valid table of contents
final: clean
	@echo "----- FINAL -----"
	OUT=Correction $(MAKE) -B correction
	sed 's/\(\\usepackage{Lapin}\)/\1\\usepackage{verbatim}/g' $(IN).tex > $(TMP)/$(IN).tex
ifeq ($(UNAME),Darwin)
	sed -i .bak 's/\\begin{Correction}/\\begin{comment}/g' $(TMP)/$(IN).tex
	sed -i .bak 's/\\end{Correction}/\\end{comment}/g' $(TMP)/$(IN).tex
else
	sed --in-place 's/\\begin{Correction}/\\begin{comment}/g' $(TMP)/$(IN).tex
	sed --in-place 's/\\end{Correction}/\\end{comment}/g' $(TMP)/$(IN).tex
endif
	IN=$(TMP)/$(IN) OUT=Enonce $(MAKE) -B enonce

enonce: temp/$(OUT).dvi
	@echo "----- ENONCE -----"
	$(MAKE) -B pdf

correction: temp/$(OUT).dvi
	@echo "----- CORRECTION -----"
	$(MAKE) -B pdf

# To create a draft version of the document.
# It execute a faster compilation without images.
# This is the default target, called by 'all'
draft: temp img
	@sed 's/^\(\\documentclass\[\)\(.*\)/\1draft,\2/g' $(IN).tex > $(TMP)/$(IN).tex
	IN=$(TMP)/$(IN) $(MAKE) pdf

# To create the PDF file
pdf: $(OUT).pdf

# To create the PS file
ps: $(OUT).ps

# To create the DVI file
dvi: $(OUT).dvi

# To convert all images
img: images/Makefile
	(cd images && $(MAKE))

# Just take the created PDF file to copy it in the current directory
$(OUT).pdf: temp/$(OUT).pdf
	cp $< $(OUT).pdf

# Just take the created PS file to copy it in the current directory
$(OUT).ps: temp/$(OUT).ps
	cp $< $(OUT).ps

# Just take the created DVI file to copy it in the current directory
$(OUT).dvi: temp/$(OUT).dvi
	cp $< $(OUT).dvi

# Create the PDF file with the PS file
temp/$(OUT).pdf: temp/$(OUT).ps
	@echo "----- CONVERSION PS -> PDF -----"
	$(PS2PDF) $(PS2PDFOPT) $< $@

# Create the PS file with the DVI file
temp/$(OUT).ps: temp/$(OUT).dvi
	@echo "----- CONVERSION DVI -> PS -----"
	$(DVIPS) $(DVIPSOPT) -o $@ $<

# Create the DVI file with the TeX file
# We need the temp directory
temp/$(OUT).dvi: $(IN).tex temp 
	@echo "----- CONVERSION TEX -> DVI -----"
	(cd images && $(MAKE))
	$(TEX) $(TEXOPT) -jobname=$(OUT) $<

temp:
	mkdir -p $@

# Create the directory where the pictures are
images:
	mkdir -p $@

# Create the 'Makefile' file for the conversion of images from PNG to EPS 
# format
images/Makefile: images
	echo -e $(MKIMG) > $@

# To clean the 'temp' directory
clean:
	(cd images && $(MAKE) $@)
	rm -Rf $(TMP)

# To clean the 'temp' directory and suppress all created files
proper: clean
	(cd images && $(MAKE) $@)
	rm -f $(OUT).dvi $(OUT).ps $(OUT).pdf
