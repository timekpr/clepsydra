# Copyright (c) 2014 Olli-Pekka Wallin <opwallin@gmail.com>

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

TEMPLATE = subdirs
CONFIG += debug_and_release
CONFIG += ordered
SUBDIRS =  app

OTHER_FILES += etc/clepsydra/* \
           etc/logrotate.d/* \
          timekprc_example

isEmpty(ETC_PREFIX) {
    ETC_PREFIX = /etc
}

FILESETTINGDIR = $$ETC_PREFIX/clepsydra
LOGRORATEDIR = $$ETC_PREFIX/logrotate.d

settings_target.path = $$FILESETTINGDIR
settings_target.files = etc/clepsydra/clepsydra.conf etc/clepsydra/clepsydradefault

logrotate_target.path = $$LOGRORATEDIR
logrotate_target.files = etc/logrotate.d/clepsydra

OTHER_FILES += ../etc/clepsydra/clepsydra.conf
OTHER_FILES += ../etc/clepsydra/clepsydradefault

INSTALLS = settings_target logrotate_target
