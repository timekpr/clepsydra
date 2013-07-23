#!/bin/python
""" timekpr setup.py
    Usage: python setup.py --help

    Requirements:
     - python 2.7
     - python-distutils
     - python-distutils-extra (https://launchpad.net/python-distutils-extra/+download)
"""

#    Copyright (C) 2012 Savvas Radevic <vicedar@gmail.com>

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

import sys
import os
import os.path
import glob

from timekpr import __version__
from distutils.command.install import install
from distutils.command.clean import clean
from distutils.core import setup
#from DistUtilsExtra.command import *

### CUSTOM CLEAN ###
class clean_custom(clean):
    def clean_dirspy(self):
        if self.verbose:
            print("removing generated 'timekpr/dirs.py'")
        tdirs = "timekpr/dirs.py"
        if not self.dry_run and os.path.isfile(tdirs):
            os.remove(tdirs)

    def clean_pyc(self):
        if self.verbose:
            print("removing generated timekpr/*.pyc")
        pyc = glob.glob("timekpr/*.pyc")
        if pyc:
            for f in pyc:
                if self.verbose:
                    print("removing '{0}'".format(f))
                if not self.dry_run:
                    os.remove(f)

    def run(self):
        self.clean_dirspy()
        self.clean_pyc()
        clean.run(self)

### CUSTOM INSTALL ###
# python setup.py install --help
# python setup.py -n install --login-defs "/etc/login.test.file"
class install_custom(install):
    install.user_options.extend([
        ### timekpr-related files/dirs
        ('log-file=', None, 'path to log file (default: /var/log/timekpr.log)'),
        ('settings-dir=', None, 'path to directory for configuration and settings files (default: /etc/timekpr)'),
        ('work-dir=', None, 'path to working directory (default: /var/lib/timekpr)'),
        ('shared-dir=', None, 'path to shared directory (default: /usr/share/timekpr)'),
        ('daemon-dir=', None, 'path to init directory (default: /etc/init.d)'),
        ### system files/dirs, used by timekpr
        ('login-defs=', None, 'path to login defaults file (default: /etc/login.defs)'),
        ('pam-time-conf=', None, 'path to linux PAM time.conf (default: /etc/security/time.conf)'),
        ('pam-access-conf=', None, 'path to linux PAM access.conf (default: /etc/security/access.conf)'),
    ])
    
    boolean_options = install.boolean_options
    negative_opt = install.negative_opt

    def substitute_dirs(self):
        """ Create timekpr/dirs.py from timekpr/dirs.py.in
            using setup.cfg variables
        """
        if self.verbose:
            print("creating timekpr/dirs.py from timekpr/dirs.py.in")
        if self.dry_run:
            return
        with open("timekpr/dirs.py.in", "r") as f:
            temp = f.read()
        temp2 = temp.format(
            ### timekpr-related files/dirs
            log_file = self.log_file,
            settings_dir = self.settings_dir, 
            work_dir = self.work_dir,
            shared_dir = self.shared_dir,
            daemon_dir = self.daemon_dir,
            ### system files/dirs, used by timekpr
            login_defs = self.login_defs,
            pam_time_conf = self.pam_time_conf,
            pam_access_conf = self.pam_access_conf,
        )
        with open("timekpr/dirs.py", "w") as f:
            f.write(temp2)

    def initialize_options(self):
        ### timekpr-related files/dirs
        self.log_file = None
        self.settings_dir = None
        self.work_dir = None
        self.shared_dir = None
        self.daemon_dir = None
        ### system files/dirs, used by timekpr
        self.login_defs = None
        self.pam_time_conf = None
        self.pam_access_conf = None
        install.initialize_options(self)

    def finalize_options(self):
        # Read default values for timekpr directories from setup.cfg
        dist = self.distribution
        vals = dist.get_option_dict('install')
        ### timekpr-related files/dirs
        self.log_file = os.path.join(self.root, vals['log_file'][1])
        self.settings_dir = os.path.join(self.root, vals['settings_dir'][1])
        self.work_dir = os.path.join(self.root, vals['work_dir'][1])
        self.shared_dir = os.path.join(self.root, vals['shared_dir'][1])
        self.daemon_dir = os.path.join(self.root, vals['daemon_dir'][1])
        ### system files/dirs, used by timekpr
        self.login_defs = os.path.join(self.root, vals['login_defs'][1])
        self.pam_time_conf = os.path.join(self.root, vals['pam_time_conf'][1])
        self.pam_access_conf = os.path.join(self.root, vals['pam_access_conf'][1])
        install.finalize_options(self)

    def run(self):
        if self.verbose:
            self.no_compile = None
            print(self.dump_options())
        self.substitute_dirs()
        install.run(self)

if sys.version < '2.7':
    sys.exit('ERROR: Sorry, python 2.7 or higher is required for this application.')

print("timekpr version {0}".format(__version__))
setup(
    name = 'timekpr',
    version = __version__,
    url = 'https://launchpad.net/timekpr',

    description = 'Keep control of computer usage',
    long_description = open('README'),

    author = 'Savvas Radevic',
    author_email = 'vicedar@gmail.com',
    maintainer = 'Savvas Radevic',
    maintainer_email = 'vicedar@gmail.com',

    license = 'GPL-3',
    keywords = 'system admin time limit access account lock tracking',

    packages = ['timekpr'],
    data_files = [
        ('share/icons/hicolor/scalable/apps', ['data/timekpr.svg']),
    ],
    cmdclass = {
        #"build": build_extra.build_extra,
        "clean": clean_custom,
        "install": install_custom,
        #"build_i18n":  build_i18n.build_i18n,
        #"build_help":  build_help.build_help,
        #"build_icons":  build_icons.build_icons,
    },
    #scripts = ["scripts/timekpr"],
)
