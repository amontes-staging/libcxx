##
# libcpp Makefile
##

SRCDIRS = .
DESTDIR = $(DSTROOT)

OBJROOT=.
SYMROOT=.
export TRIPLE=-apple-

ifeq (,$(RC_INDIGO))
	INSTALL_PREFIX=""
else
	INSTALL_PREFIX="$(SDKROOT)"
endif
INSTALL_DIR=$(DSTROOT)/$(INSTALL_PREFIX)

.PHONY: help installsrc clean installhdrs do-installhdrs install

help::
	echo Use make install DSTROOT=<destination>

installsrc:: $(SRCROOT)

	ditto $(SRCDIRS)/include $(SRCROOT)/include
	ditto $(SRCDIRS)/lib $(SRCROOT)/lib
	ditto $(SRCDIRS)/src $(SRCROOT)/src
	ditto $(SRCDIRS)/Makefile $(SRCROOT)/Makefile

clean::

installhdrs::

	$(MAKE) HEADER_DIR=$(INSTALL_DIR)/usr/include do-installhdrs
	$(MAKE) HEADER_DIR=$(INSTALL_DIR)/usr/lib do-installhdrs
	$(MAKE) HEADER_DIR=$(INSTALL_DIR)/usr/clang-ide/lib do-installhdrs
	$(MAKE) HEADER_DIR=$(INSTALL_DIR)/Developer/usr/lib do-installhdrs
	$(MAKE) HEADER_DIR=$(INSTALL_DIR)/Developer/Platforms/iPhoneOS.platform/usr/lib do-installhdrs

# The do-installhdrs target is also used by clang's runtime/libcxx makefile.
do-installhdrs:
	mkdir -p $(HEADER_DIR)/c++/v1/ext
	rsync -r --exclude=".*" --exclude="support" $(SRCDIRS)/include/* \
	  $(HEADER_DIR)/c++/v1/
	chown -R root:wheel $(HEADER_DIR)/c++
	chmod 755 $(HEADER_DIR)/c++/v1
	chmod 644 $(HEADER_DIR)/c++/v1/*
	chmod 755 $(HEADER_DIR)/c++/v1/ext
	chmod 644 $(HEADER_DIR)/c++/v1/ext/*

install:: installhdrs $(DESTDIR)

	cd lib && ./buildit
	ditto lib/libc++.1.dylib $(SYMROOT)/usr/lib/libc++.1.dylib
	cd lib && dsymutil -o $(SYMROOT)/libc++.1.dylib.dSYM \
	  $(SYMROOT)/usr/lib/libc++.1.dylib
	mkdir -p $(INSTALL_DIR)/usr/lib
	strip -S -o $(INSTALL_DIR)/usr/lib/libc++.1.dylib \
	  $(SYMROOT)/usr/lib/libc++.1.dylib
	cd $(INSTALL_DIR)/usr/lib && ln -s libc++.1.dylib libc++.dylib
