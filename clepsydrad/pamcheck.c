// Copyright (c) 2015 Olli-Pekka Wallin <opwallin@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>

#include <utmp.h>
#include <err.h>

#include <security/pam_appl.h>
#include <security/pam_misc.h>
#include <stdio.h>

FILE *utmpFile(char *name);
#define NAME_WIDTH  8

int getLoggedusers (FILE *lfp)
{
    FILE *ufp;
    int numberOfUsers = 0;
    struct utmp usr;
    ufp = utmpFile(_PATH_UTMP);
    // fprintf(lfp, " utmp ... %s\n",  _PATH_UTMP);
    while (fread((char *)&usr, sizeof(usr), 1, ufp) == 1) {
        if (*usr.ut_name && *usr.ut_line && *usr.ut_line != '~') {
            if (usr.ut_type == USER_PROCESS) {
                fprintf(lfp, " utmp ... %s\n", usr.ut_user );
                numberOfUsers++;
            }
        }
    }
    return numberOfUsers;
}

FILE *utmpFile(char *name)
{
    FILE *ufp;
    if (!(ufp = fopen(name, "r"))) {
        err(1, "%s", name);
    }
    return(ufp);
}

static struct pam_conv conv = {
    misc_conv,
    NULL
};

int checkPamUser ()
{
    pam_handle_t *pamh=NULL;
    int retval;
    const char *user="nobody";

    retval = pam_start("check_user", user, &conv, &pamh);
    if (retval != PAM_SUCCESS)  {
        return -1;
    }
    return 0;
}
