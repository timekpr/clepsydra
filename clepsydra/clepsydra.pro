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

isEmpty(ETC_PREFIX) {
    ETC_PREFIX = /etc
}

isEmpty(VAR_PREFIX) {
    VAR_PREFIX = /var/lib
}

FILESETTINGDIR = $$ETC_PREFIX/clepsydra
WORKING_FOLDER = $$VAR_PREFIX/clepsydra

LOGRORATEDIR = $$ETC_PREFIX/logrotate.d

settings_target.path = $$FILESETTINGDIR
settings_target.files += config/clepsydra/clepsydra.conf
settings_target.files += config/clepsydra/clepsydradefault.json

working_lib_target.path = $$WORKING_FOLDER
working_lib_target.files += config/clepsydra/clepsydralimits.json

logrotate_target.path = $$LOGRORATEDIR
logrotate_target.files = config/logrotate.d/clepsydra

OTHER_FILES +=  config/clepsydra/clepsydra.conf
OTHER_FILES +=  config/clepsydra/clepsydradefault.json
OTHER_FILES +=  config/clepsydra/clepsydralimits.json

CONFIG(debug) {
    message (debug build 2)
}

INSTALLS += settings_target working_lib_target logrotate_target
