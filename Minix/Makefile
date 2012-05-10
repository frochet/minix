MINIX_DIR=/etinfo/applications/minix

MINIX_ORIG_SRC=$(MINIX_DIR)/src
MINIX_LOCAL_SRC=./src
MINIX_LOCAL_ORIG_SRC=./src_orig
MINIX_ORIG_SRC_COPY=include,lib,man,servers,kernel
MINIX_LOCAL_TEST=./test

MINIX_ORIG_DISK=$(MINIX_DIR)/minix_orig.img
MINIX_LOCAL_DISK=minix_local.cow

MINIX_ADD_DISK=additional_disk.img
MINIX_ADD_DISK_SIZE=50M

QEMU=qemu
QEMU_IMG=qemu-img
QEMU_OPTS=-localtime -k fr-be -net user -net nic -m 256 -hda $(MINIX_LOCAL_DISK) -hdb $(MINIX_ADD_DISK)

PATCH_FILE=minix_3.1.8r3_nfrags_defrag_$(USER).patch
REPORT_FILE=rapport.pdf
ARCHIVE_FILE=projet_minix_$(USER).tgz

all: 
	@echo "Utilisez 'make <target>' où <target> est :"
	@echo "  init         pour initialiser le répertoire du projet"
	@echo "  run          pour executer la machine virtuelle (en console)"
	@echo "  run_x11      pour executer la machine virtuelle (en fenêtre)"
	@echo "  patch        pour générer le patch"
	@echo "  dist         pour générer une archive comprenant le patch, le"
	@echo "               rapport et le dossier test."
	@echo "  clean        supprime l'archive et le patch"
	@echo "  mrproper     supprime les disques virtuels"

init: $(MINIX_LOCAL_DISK) $(MINIX_ADD_DISK) $(MINIX_LOCAL_SRC) $(MINIX_LOCAL_ORIG_SRC) $(MINIX_LOCAL_TEST)
	
run: init $(MINIX_LOCAL_DISK) $(MINIX_ADD_DISK)
	@$(QEMU) -curses $(QEMU_OPTS) 2> /dev/null 

run_x11: $(MINIX_LOCAL_DISK) $(MINIX_ADD_DISK)
	@$(QEMU) $(QEMU_OPTS)

patch: $(PATCH_FILE)

dist: clean $(ARCHIVE_FILE)
	
clean:
	@rm -f $(PATCH_FILE) $(ARCHIVE_FILE)

mrproper: clean
	@rm -f $(MINIX_LOCAL_DISK) $(MINIX_ADD_DISK)	
	
$(MINIX_LOCAL_DISK): $(MINIX_ORIG_DISK)
	@echo -n "Creation du disque virtuel: $@... "
	@$(QEMU_IMG) create -f qcow2 -b $^ $@ > /dev/null
	@echo "done."

$(MINIX_ADD_DISK): 
	@echo -n "Creation du disque virtuel: $@... "
	@$(QEMU_IMG) create $@ $(MINIX_ADD_DISK_SIZE) > /dev/null
	@echo "done."

$(MINIX_LOCAL_SRC): $(MINIX_ORIG_SRC)
	@echo -n "Creation du dossier: $@... "
	@mkdir -p $@
	@ln -sf $^/* $@
	@rm -f $@/{$(MINIX_ORIG_SRC_COPY)}
	@cp -rf $^/{$(MINIX_ORIG_SRC_COPY)} $@
	@echo "done."

$(MINIX_LOCAL_ORIG_SRC): $(MINIX_ORIG_SRC)
	@echo -n "Creation du lien symbolique: $@... "
	@ln -s $^ $@
	@echo "done."

$(MINIX_LOCAL_TEST):
	@echo -n "Creation du dossier: $@... "
	@mkdir -p $@
	@echo "done."

$(PATCH_FILE): $(MINIX_LOCAL_SRC) $(MINIX_LOCAL_ORIG_SRC)
	@echo -n "Génération du patch: $@... "
	@diff -urN $(MINIX_LOCAL_ORIG_SRC) $(MINIX_LOCAL_SRC) --exclude ".svn" --exclude "*~" > $@; exit 0
	@echo "done."

$(REPORT_FILE):
	@echo "Vous devez copier votre rapport.pdf dans ce répertoire."
	@exit 1

$(ARCHIVE_FILE): init $(PATCH_FILE) $(REPORT_FILE)
	@echo -n "Génération de l'archive: $@... "
	@tar -pczf $@ $(PATCH_FILE) $(REPORT_FILE) $(MINIX_LOCAL_TEST)
	@echo "done."

.PHONY: all init run run_x11 patch dist clean mrproper

