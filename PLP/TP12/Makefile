# Repertoires
IMG=Images
BUILD=Build

# Fichiers d'entrée et de sortie (sans les extensions)
IN=TP12
INDRAFT=$(IN)Draft
OUT=EnonceTP12
OUTC=CorrectionTP12
OUTDRAFT=$(OUT)Draft

# Compilateurs
TEX=latex
DVIPS=dvips
PS2PDF=ps2pdf

# Options de compilateurs
TEXOPT=-shell-escape -output-format=dvi -output-directory=$(BUILD)
DVIPSOPT=-R0
PS2PDFOPT=

# Makefile pour les images
MKIMG='PNG=\044(wildcard *.png)\nEPS=\044(PNG:.png=.eps)\n\nall: \044(EPS) \044(BB)\n\t@echo ''--- IMAGES TRAITÉES ---''\n\n%.eps: %.png\n\tconvert \044< eps:->\044@\n\nclean:\n\t@echo ''--- RIEN À ENLEVER ---''\nproper:\n\t@rm -f *.eps\n'

.PHONY: final clean proper

all: $(BUILD) $(IMG)
	@(cd $(IMG) && $(MAKE))
	sed 's/^\(\\documentclass\[\)\(.*\)/\1draft,\2/g' $(IN).tex > $(BUILD)/$(INDRAFT).tex
	$(TEX) $(TEXOPT) -jobname=$(OUTDRAFT) $(INDRAFT).tex
	$(DVIPS) $(DVIPSOPT) -o $(BUILD)/$(OUTDRAFT).ps $(BUILD)/$(OUTDRAFT).dvi
	$(PS2PDF) $(PS2PDFOPT) $(BUILD)/$(OUTDRAFT).ps $(OUTC).pdf
	sed 's/\(\\newenvironment{Correction}{\).*}/\\usepackage{verbatim}/g' $(BUILD)/$(INDRAFT).tex > $(BUILD)/TEMP
	sed 's/\\begin{Correction}/\\begin{comment}/g' $(BUILD)/TEMP > $(BUILD)/TEMP2
	sed 's/\\end{Correction}/\\end{comment}/g' $(BUILD)/TEMP2 > $(BUILD)/$(INDRAFT).tex
	$(TEX) $(TEXOPT) -jobname=$(OUTDRAFT) $(INDRAFT).tex
	$(DVIPS) $(DVIPSOPT) -o $(BUILD)/$(OUTDRAFT).ps $(BUILD)/$(OUTDRAFT).dvi
	$(PS2PDF) $(PS2PDFOPT) $(BUILD)/$(OUTDRAFT).ps $(OUT).pdf

final: $(BUILD) $(IMG) proper
	@(cd $(IMG) && $(MAKE))
	-$(TEX) $(TEXOPT) -jobname=$(OUTC) $(IN).tex
	$(TEX) $(TEXOPT) -jobname=$(OUTC) $(IN).tex
	$(DVIPS) $(DVIPSOPT) -o $(BUILD)/$(OUTC).ps $(BUILD)/$(OUTC).dvi
	$(PS2PDF) $(PS2PDFOPT) $(BUILD)/$(OUTC).ps $(OUTC).pdf
	sed 's/\(\\newenvironment{Correction}{\).*}/\\usepackage{verbatim}/g' $(IN).tex > $(BUILD)/TEMP
	sed 's/\\begin{Correction}/\\begin{comment}/g' $(BUILD)/TEMP > $(BUILD)/TEMP2
	sed 's/\\end{Correction}/\\end{comment}/g' $(BUILD)/TEMP2 > $(BUILD)/$(IN).tex
	-$(TEX) $(TEXOPT) -jobname=$(OUT) $(BUILD)/$(IN).tex
	$(TEX) $(TEXOPT) -jobname=$(OUT) $(BUILD)/$(IN).tex
	$(DVIPS) $(DVIPSOPT) -o $(BUILD)/$(OUT).ps $(BUILD)/$(OUT).dvi
	$(PS2PDF) $(PS2PDFOPT) $(BUILD)/$(OUT).ps $(OUT).pdf

$(BUILD):
	@mkdir $@

$(IMG):
	@mkdir $@
	@echo $(MKIMG) > $@/Makefile

clean:
	@(cd $(IMG) && $(MAKE) $@)
	@rm -f $(BUILD)/*
	@echo "--- Répertoire nettoyé ---"

proper: clean
	@(cd $(IMG) && $(MAKE) $@)
	@rm -f $(OUT).pdf
	@echo "--- Projet nettoyé ---"
