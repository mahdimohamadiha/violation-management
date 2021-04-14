//username supervisor : meyti
//password supervisor : 4321

//username legal : mahdi
//password legal :1234

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <menu.h>
#include <time.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

int win_registerORlogin();
int menu_registerORlogin();
int create_win2();
int Register();
int Login();
int create_win3();
int Login2();
int Login3();
int publicSection();
int record_new_violations();
int Inbox();
int History(int peopleOrlegal, long int national_code);
int create_win4();
int Edit_reports();
int Related_reports();
int LegalUnit();
int legal_Inbox();
int Block_user();
int Encourage_user();
int menu_public_registration();
int menu_public_registration2();
int menu_public_login();
int menu_public_login2(long int national_code);
int menu_legal_login();
int menu_legal_login2();
int menu_Supervisor_login();
int menu_Supervisor_login2();
int create_win5();
int create_win6();
int create_win7();
int create_win8();
int Edit(long int national_code);
int Delete(long int national_code);
int menu_inbox(long int national_code);
int menu_related_reports(long int national_code);
int menu_legal_inbox();
int confirmation();
int reject();
int block_user2();
int menu_block_user();
int Encourage_user2();
int menu_encourage_user();
int Supervisor_section();
int Supervisor_inbox();
int menu_Supervisor_inbox();
int confirmation2();
int reject2();
int shut_down_system();
int Shut_down();
int opening();
int menu_public_login3();

struct Register
{
    char user_name[30];
    long int national_code;
    char password[30];
    int Incentive_money;
};

struct Login
{
    char user_name2[30];
    char password2[30];
};

struct RecordNewViolations
{
    int num;
    char type[30];
    char description[200];
    char placeViolation[100];
    char nationalCode[20];
    char time[25];
    int ApproveORrejectORsupervisor;
    int Instant_mode;
    long int national_code2;
    char rejectReport[300];
};

struct Time
{
    int day;
    int hour;
};

struct EpochTime
{
    long int epoch1;
    long int epoch2;
};

char *ch_publicSection[] = {
    "Inbox",
    "History",
    "Record new violations",
    "Related reports",
    "Exit",
    (char *)NULL,
};

char *ch_LegalUnit[] = {
    "Inbox",
    "History",
    "Block user",
    "Encourage the user",
    "Shut down the system",
    "Exit",
    (char *)NULL,
};

char *ch_start[] = {
    "Public registration",
    "public login",
    "Supervisor login",
    "legal login",
    "Exit",
    (char *)NULL,
};

char *ch_public_registration[] = {
    "re-register",
    "Exit",
    (char *)NULL,
};

char *ch_public_registration2[] = {
    "login page",
    "Exit",
    (char *)NULL,
};

char *ch_public_login[] = {
    "register page",
    "re-login",
    "Exit",
    (char *)NULL,
};

char *ch_public_login3[] = {
    "register page",
    "re-login",
    "Forgot password",
    "Exit",
    (char *)NULL,
};

char *ch_public_login2[] = {
    "public section",
    "Exit",
    (char *)NULL,
};

char *ch_legal_login[] = {
    "re-login",
    "Exit",
    (char *)NULL,
};

char *ch_legal_login2[] = {
    "Legal Unit",
    "Exit",
    (char *)NULL,
};

char *ch_inbox[] = {
    "public section",
    "edit reports",
    "Delete reports",
    (char *)NULL,
};

char *ch_related_reports[] = {
    "public section",
    "View related reports",
    (char *)NULL,
};

char *ch_legal_inbox[] = {
    "Legal Unit",
    "Confirmation",
    "Reject",
    (char *)NULL,
};

char *ch_block_user[] = {
    "Legal Unit",
    "block user",
    (char *)NULL,
};

char *ch_encourage_user[] = {
    "Legal Unit",
    "Encourage the user",
    (char *)NULL,
};

char *ch_Supervisor_login[] = {
    "Supervisor section",
    "Exit",
    (char *)NULL,
};

char *ch_Supervisor_section[] = {
    "Inbox",
    "History",
    "Exit",
    (char *)NULL,
};

char *ch_Supervisor_inbox[] = {
    "Supervisor section",
    "Confirmation",
    "Reject",
    (char *)NULL,
};

char *ch_shut_down_system[] = {
    "Legal Unit",
    "Shut down",
    "opening",
    (char *)NULL,
};

int main()
{
    initscr();
    curs_set(0);
    refresh();
    win_registerORlogin();
    menu_registerORlogin();
    endwin();
    return 0;
}

int win_registerORlogin()
{
    usleep(300000);
    WINDOW *win;
    win = newwin(0, 0, 0, 0);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    win = newwin(18, 62, 10, 44);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    mvprintw(11, 51, "Welcome to the organizational application for ");
    mvprintw(13, 47, "managing violations and optimizing the country's lands");
    mvprintw(14, 45, "------------------------------------------------------------");
    mvprintw(15, 45, "------------------------------------------------------------");
    return 0;
}

int menu_registerORlogin()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    /* Initialize items */
    n_choices = ARRAY_SIZE(ch_start);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_start[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    /* Create menu */
    my_menu = new_menu((ITEM **)my_items);

    /* Make the menu multi valued */
    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(9, 31, 17, 58);
    keypad(my_menu_win, TRUE);

    /* Set main window and sub window */
    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 25, 2, 3));
    set_menu_format(my_menu, 6, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    /* Post the menu */
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Public registration", item_name(current_item(my_menu))))
            {
                create_win2();
                Register();
                return 0;
            }
            if (0 == strcmp("public login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login();
                return 0;
            }
            if (0 == strcmp("Supervisor login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login3();
                return 0;
            }
            if (0 == strcmp("legal login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login2();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int create_win2()
{
    refresh();
    WINDOW *win2;
    win2 = newwin(0, 0, 0, 0);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
    win2 = newwin(20, 50, 8, 50);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
    mvprintw(12, 51, "************************************************");
    mvprintw(20, 51, "________________________________________________");
    mvprintw(21, 51, "________________________________________________");
}

int Register()
{
    int digit = 0;
    struct Register r;
    char save_username[30];
    long int save_national_code;
    char save_password[30];
    echo();
    mvprintw(10, 62, "-< Public registration >-");
    mvprintw(14, 56, "Enter your user name : ");
    scanw("%s", r.user_name);
    strcpy(save_username, r.user_name);
    mvprintw(16, 56, "Enter your national code : ");
    scanw("%ld", &r.national_code);
    save_national_code = r.national_code;
    noecho();
    while (r.national_code != 0)
    {
        r.national_code /= 10;
        digit++;
    }
    if (10 != digit)
    {
        mvprintw(23, 56, "The national code must be ten digits");
        menu_public_registration();
        return 0;
    }
    echo();
    mvprintw(18, 56, "Enter your password : ");
    scanw("%s", r.password);
    strcpy(save_password, r.password);
    noecho();
    FILE *fp = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp))
    {
        if (0 == strcmp(save_username, r.user_name))
        {
            mvprintw(23, 63, "Username already exist");
            menu_public_registration();
            return 0;
        }
    }
    fclose(fp);
    FILE *fp3 = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp3))
    {
        if (save_national_code == r.national_code)
        {
            mvprintw(23, 60, "national code already exist");
            menu_public_registration();
            return 0;
        }
    }
    fseek(fp3, 0, SEEK_SET);
    fclose(fp3);
    strcpy(r.user_name, save_username);
    r.national_code = save_national_code;
    strcpy(r.password, save_password);
    r.Incentive_money = 0;
    FILE *fp2 = fopen("Registered.dat", "a+");
    fwrite(&r, sizeof(struct Register), 1, fp2);
    fclose(fp2);
    mvprintw(23, 59, "Register completed successfully");
    menu_public_registration2();
    return 0;
}

int menu_public_registration()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_public_registration);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_public_registration[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("re-register", item_name(current_item(my_menu))))
            {
                create_win2();
                Register();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int menu_public_registration2()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_public_registration2);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_public_registration2[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("login page", item_name(current_item(my_menu))))
            {
                create_win2();
                Login();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Login()
{
    struct Register r;
    struct Login l;
    time_t now;
    struct EpochTime e;
    echo();
    mvprintw(10, 65, "-< public login >-");
    mvprintw(14, 56, "Enter your user name : ");
    scanw("%s", l.user_name2);
    mvprintw(17, 56, "Enter your password : ");
    scanw("%s", l.password2);
    noecho();
    time(&now);
    FILE *fp7 = fopen("Time.dat", "a+");
    while (fread(&e, sizeof(struct EpochTime), 1, fp7))
    {
        if (e.epoch1 <= now && now <= e.epoch2)
        {
            mvprintw(23, 63, "The system is shut down");
            menu_public_login();
            return 0;
        }
    }
    fclose(fp7);
    FILE *fp = fopen("Blocked.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp))
    {
        if (0 == strcmp(l.user_name2, r.user_name))
        {
            mvprintw(23, 65, "The user is blocked");
            menu_public_login();
            return 0;
        }
    }
    FILE *fp3 = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp3))
    {
        if (0 == strcmp(l.user_name2, r.user_name) && 0 == strcmp(r.password, l.password2))
        {
            mvprintw(23, 60, "Login completed successfully");
            menu_public_login2(r.national_code);
            return 0;
        }
    }
    fclose(fp3);
    mvprintw(22, 55, "Worong password or no username available");
    menu_public_login3();
    return 0;
}

int menu_public_login()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_public_login);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_public_login[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 3, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("register page", item_name(current_item(my_menu))))
            {
                create_win2();
                Register();
                return 0;
            }
            if (0 == strcmp("re-login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int menu_public_login2(long int national_code)
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_public_login2);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_public_login2[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("public section", item_name(current_item(my_menu))))
            {
                create_win3();
                publicSection(national_code);
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Login2()
{
    struct Register r;
    strcpy(r.user_name, "mahdi");
    strcpy(r.password, "1234");
    struct Login l;
    echo();
    mvprintw(10, 65, "-< legal login >-");
    mvprintw(14, 56, "Enter your user name : ");
    scanw("%s", l.user_name2);
    mvprintw(17, 56, "Enter your password : ");
    scanw("%s", l.password2);
    noecho();
    if (0 == strcmp(l.user_name2, r.user_name) && 0 == strcmp(r.password, l.password2))
    {
        mvprintw(23, 60, "Login completed successfully");
        menu_legal_login2();
        return 0;
    }
    mvprintw(23, 55, "Worong password or no username available");
    menu_legal_login();
    return 0;
}

int Login3()
{
    struct Register r;
    strcpy(r.user_name, "meyti");
    strcpy(r.password, "4321");
    struct Login l;
    echo();
    mvprintw(10, 62, "-< Supervisor login >-");
    mvprintw(14, 56, "Enter your user name : ");
    scanw("%s", l.user_name2);
    mvprintw(17, 56, "Enter your password : ");
    scanw("%s", l.password2);
    noecho();
    if (0 == strcmp(l.user_name2, r.user_name) && 0 == strcmp(r.password, l.password2))
    {
        mvprintw(23, 60, "Login completed successfully");
        menu_Supervisor_login2();
        return 0;
    }
    mvprintw(23, 55, "Worong password or no username available");
    menu_Supervisor_login();
    return 0;
}

int menu_legal_login()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_legal_login);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_legal_login[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("re-login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login2();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int menu_legal_login2()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_legal_login2);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_legal_login2[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Legal Unit", item_name(current_item(my_menu))))
            {
                create_win3();
                LegalUnit();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int menu_Supervisor_login()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_legal_login);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_legal_login[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 20, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("re-login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login3();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int menu_Supervisor_login2()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_Supervisor_login);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_Supervisor_login[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 59);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 3, 23, 1, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Supervisor section", item_name(current_item(my_menu))))
            {
                create_win3();
                Supervisor_section();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int create_win3()
{
    WINDOW *win2;
    win2 = newwin(0, 0, 0, 0);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
}

int create_win4()
{
    WINDOW *win2;
    win2 = newwin(36, 71, 1, 38);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
}

int create_win5()
{
    WINDOW *win4;
    win4 = newwin(10, 30, 14, 56);
    refresh();
    box(win4, 0, 0);
    wrefresh(win4);
    WINDOW *win3;
    win3 = newwin(10, 30, 10, 62);
    refresh();
    box(win3, 0, 0);
    wrefresh(win3);
    WINDOW *win;
    win = newwin(10, 30, 9, 54);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    WINDOW *win2;
    win2 = newwin(10, 30, 15, 64);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
}

int create_win6()
{
    WINDOW *win2;
    win2 = newwin(5, 18, 15, 120);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
}

int create_win7()
{
    WINDOW *win2;
    win2 = newwin(23, 110, 8, 20);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
}

int create_win8()
{
    WINDOW *win;
    win = newwin(32, 40, 5, 38);
    refresh();
    box(win, 0, 0);
    wrefresh(win);
    WINDOW *win2;
    win2 = newwin(32, 40, 5, 80);
    refresh();
    box(win2, 0, 0);
    wrefresh(win2);
}

int publicSection(long int national_code)
{
    mvprintw(3, 30, "  ____            _       _   _             ____                  _     _                 ");
    mvprintw(4, 30, " |  _ \\   _   _  | |__   | | (_)   ___     / ___|    ___    ___  | |_  (_)   ___    _ __  ");
    mvprintw(5, 30, " | |_) | | | | | | '_ \\  | | | |  / __|    \\___ \\   / _ \\  / __| | __| | |  / _ \\  | '_ \\ ");
    mvprintw(6, 30, " |  __/  | |_| | | |_) | | | | | | (__      ___) | |  __/ | (__  | |_  | | | (_) | | | | |");
    mvprintw(7, 30, " |_|      \\__,_| |_.__/  |_| |_|  \\___|    |____/   \\___|  \\___|  \\__| |_|  \\___/  |_| |_|");
    struct Register r;
    FILE *fp = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp))
    {
        if (national_code == r.national_code)
        {
            mvprintw(28, 62, "Incentive money : %d", r.Incentive_money);
        }
    }
    fclose(fp);
    refresh();
    create_win5();
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_publicSection);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_publicSection[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(10, 28, 12, 60);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 25, 3, 1));
    set_menu_format(my_menu, 5, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Inbox", item_name(current_item(my_menu))))
            {
                create_win3();
                Inbox(national_code);
                return 0;
            }
            if (0 == strcmp("History", item_name(current_item(my_menu))))
            {
                create_win3();
                History(1, national_code);
                return 0;
            }
            if (0 == strcmp("Record new violations", item_name(current_item(my_menu))))
            {
                create_win3();
                record_new_violations(national_code);
                return 0;
            }
            if (0 == strcmp("Related reports", item_name(current_item(my_menu))))
            {
                create_win3();
                menu_related_reports(national_code);
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Inbox(long int national_code)
{
    int number = 0;
    int y = 3;
    create_win4();
    struct RecordNewViolations rnv;
    FILE *fp9 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp9))
    {
        if (rnv.Instant_mode == 1)
        {
            if (national_code == rnv.national_code2)
            {
                number++;
                rnv.num = number;
            }
            FILE *fp8 = fopen("Temp.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp8);
            fclose(fp8);
        }
        else if (rnv.Instant_mode == 0)
        {
            if (national_code == rnv.national_code2)
            {
                number++;
                rnv.num = number;
            }
            FILE *fp7 = fopen("Temp2.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp7);
            fclose(fp7);
        }
    }
    FILE *fp6 = fopen("Temp2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp11 = fopen("Temp.dat", "a+");
        fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp11);
        fclose(fp11);
    }
    fclose(fp6);
    fclose(fp9);
    rename("Temp.dat", "Violations.dat");
    remove("Temp2.dat");

    FILE *fp2 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (national_code == rnv.national_code2)
        {
            mvprintw(y - 1, 40, "Number : ");
            mvprintw(y - 1, 49, "%d", rnv.num);
            mvprintw(y, 40, "Type or title of violation : ");
            mvprintw(y, 69, "%s", rnv.type);
            mvprintw(y + 2, 40, "Time of registration of the violation : ");
            mvprintw(y + 2, 80, "%s", rnv.time);
            mvprintw(y + 4, 40, "Condition : in progress");
            if (rnv.Instant_mode == 1)
            {
                mvprintw(y + 5, 40, "Instant mode");
            }
            mvprintw(y + 6, 39, "---------------------------------------------------------------------");
            y += 8;
        }
    }
    fclose(fp2);
    menu_inbox(national_code);
    return 0;
}

int menu_inbox(long int national_code)
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_inbox);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_inbox[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(9, 26, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 20, 3, 3));
    set_menu_format(my_menu, 3, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("public section", item_name(current_item(my_menu))))
            {
                create_win3();
                publicSection(national_code);
                return 0;
            }
            if (0 == strcmp("edit reports", item_name(current_item(my_menu))))
            {
                Edit(national_code);
                return 0;
            }
            if (0 == strcmp("Delete reports", item_name(current_item(my_menu))))
            {
                Delete(national_code);
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Edit(long int national_code)
{
    int edit;
    int num;
    int n_incorrect = 0;
    struct RecordNewViolations rnv;
    create_win6();
    mvprintw(16, 123, "Number : ");
    echo();
    scanw("%d", &num);
    FILE *fp2 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (national_code == rnv.national_code2)
        {
            if (num == rnv.num)
            {
                n_incorrect++;
            }
        }
    }
    if (n_incorrect == 0)
    {
        create_win3();
        mvprintw(22, 115, "The given number is incorrect");
        Inbox(national_code);
        return 0;
    }
    fclose(fp2);
    create_win3();
    Edit_reports(national_code);
    FILE *fp4 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp4))
    {
        edit = 1;
        if (num == rnv.num)
        {
            edit = 0;
        }
        if (edit == 1)
        {
            FILE *fp3 = fopen("Temp3.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
            fclose(fp3);
        }
    }
    fclose(fp4);
    rename("Temp3.dat", "Violations.dat");
    create_win3();
    publicSection(national_code);
}

int Delete(long int national_code)
{
    int num;
    int n_incorrect = 0;
    int delete;
    int number = 0;
    struct RecordNewViolations rnv;
    create_win6();
    mvprintw(18, 123, "Number : ");
    echo();
    scanw("%d", &num);
    FILE *fp20 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp20))
    {
        if (national_code == rnv.national_code2)
        {
            if (num == rnv.num)
            {
                n_incorrect++;
            }
        }
    }
    if (n_incorrect == 0)
    {
        create_win3();
        mvprintw(22, 115, "The given number is incorrect");
        Inbox(national_code);
        return 0;
    }
    fclose(fp20);
    FILE *fp6 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp3 = fopen("Temp3.dat", "a+");
        delete = 1;
        if (num == rnv.num)
        {
            delete = 0;
        }
        if (delete == 1)
        {
            number++;
            rnv.num = number;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
            fclose(fp3);
        }
    }
    fclose(fp6);
    rename("Temp3.dat", "Violations.dat");
    create_win3();
    publicSection(national_code);
}

int History(int peopleOrlegal, long int national_code)
{
    int y = 3;
    int number = 0;
    int number2 = 0;
    int number3 = 0;
    create_win4();
    struct RecordNewViolations rnv;
    struct Register r;
    FILE *fp2 = fopen("History.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (national_code == rnv.national_code2 && peopleOrlegal == 1)
        {
            number++;
            rnv.num = number;
            mvprintw(y - 1, 40, "Number : ");
            mvprintw(y - 1, 49, "%d", rnv.num);
            refresh();
            mvprintw(y, 40, "Type or title of violation : ");
            mvprintw(y, 69, "%s", rnv.type);
            mvprintw(y + 2, 40, "Request status : ");
            if (rnv.ApproveORrejectORsupervisor == 1)
            {
                mvprintw(y + 2, 57, "Approve");
                mvprintw(y + 5, 40, "Rejected by the legal");
            }
            else if (rnv.ApproveORrejectORsupervisor == 0)
            {
                mvprintw(y + 2, 57, "Reject");
                mvprintw(y + 6, 40, "Reason for rejecting the report : ");
                mvprintw(y + 7, 40, "%s", rnv.rejectReport);
                mvprintw(y + 5, 40, "Rejected by the legal");
            }
            else if (rnv.ApproveORrejectORsupervisor == 2)
            {
                mvprintw(y + 2, 57, "Reject");
                mvprintw(y + 5, 40, "Rejected by the supervisor");
            }
            mvprintw(y + 4, 40, "Response time : ");
            mvprintw(y + 4, 56, "%s", rnv.time);
            mvprintw(y + 8, 39, "---------------------------------------------------------------------");
            y += 10;
        }
        if (peopleOrlegal == 2)
        {
            number2++;
            rnv.num = number2;
            mvprintw(y - 1, 40, "Number : ");
            mvprintw(y - 1, 49, "%d", rnv.num);
            refresh();
            FILE *fp19 = fopen("Registered.dat", "a+");
            while (fread(&r, sizeof(struct Register), 1, fp19))
            {
                if (r.national_code == rnv.national_code2)
                {
                    mvprintw(y - 1, 60, "User name : ");
                    refresh();
                    mvprintw(y - 1, 72, "%s", r.user_name);
                    refresh();
                }
            }
            fclose(fp19);
            mvprintw(y, 40, "Type or title of violation : ");
            mvprintw(y, 69, "%s", rnv.type);
            mvprintw(y + 2, 40, "Request status : ");
            if (rnv.ApproveORrejectORsupervisor == 1)
            {
                mvprintw(y + 2, 57, "Approve");
                mvprintw(y + 5, 40, "Rejected by the legal");
            }
            else if (rnv.ApproveORrejectORsupervisor == 0)
            {
                mvprintw(y + 2, 57, "Reject");
                mvprintw(y + 6, 40, "Reason for rejecting the report : ");
                mvprintw(y + 7, 40, "%s", rnv.rejectReport);
                mvprintw(y + 5, 40, "Rejected by the legal");
            }
            else if (rnv.ApproveORrejectORsupervisor == 2)
            {
                mvprintw(y + 2, 57, "Reject");
                mvprintw(y + 5, 40, "Rejected by the supervisor");
            }
            mvprintw(y + 4, 40, "Response time : ");
            mvprintw(y + 4, 56, "%s", rnv.time);
            mvprintw(y + 8, 39, "---------------------------------------------------------------------");
            y += 10;
        }
        if (rnv.ApproveORrejectORsupervisor == 2 && peopleOrlegal == 3)
        {
            number3++;
            rnv.num = number3;
            mvprintw(y - 1, 40, "Number : ");
            mvprintw(y - 1, 49, "%d", rnv.num);
            refresh();
            FILE *fp19 = fopen("Registered.dat", "a+");
            while (fread(&r, sizeof(struct Register), 1, fp19))
            {
                if (r.national_code == rnv.national_code2)
                {
                    mvprintw(y - 1, 60, "User name : ");
                    refresh();
                    mvprintw(y - 1, 72, "%s", r.user_name);
                    refresh();
                }
            }
            fclose(fp19);
            mvprintw(y, 40, "Type or title of violation : ");
            mvprintw(y, 69, "%s", rnv.type);
            mvprintw(y + 2, 40, "Request status : ");
            if (rnv.ApproveORrejectORsupervisor == 1)
            {
                mvprintw(y + 2, 57, "Approve");
                mvprintw(y + 5, 40, "Rejected by the legal");
            }
            else if (rnv.ApproveORrejectORsupervisor == 0)
            {
                mvprintw(y + 2, 57, "Reject");
                mvprintw(y + 6, 40, "Reason for rejecting the report : ");
                mvprintw(y + 7, 40, "%s", rnv.rejectReport);
                mvprintw(y + 5, 40, "Rejected by the legal");
            }
            else if (rnv.ApproveORrejectORsupervisor == 2)
            {
                mvprintw(y + 2, 57, "Reject");
                mvprintw(y + 5, 40, "Rejected by the supervisor");
            }
            mvprintw(y + 4, 40, "Response time : ");
            mvprintw(y + 4, 56, "%s", rnv.time);
            mvprintw(y + 8, 39, "---------------------------------------------------------------------");
            y += 10;
        }
    }
    fclose(fp2);
    getch();
    switch (peopleOrlegal)
    {
    case 1:
        create_win3();
        publicSection(national_code);
        break;
    case 2:
        create_win3();
        LegalUnit();
        break;
    case 3:
        create_win3();
        Supervisor_section();
        break;
    }
    return 0;
}

int record_new_violations(long int national_code)
{
    struct RecordNewViolations rnv;
    char choice = 't';
    rnv.num = 1;
    create_win7();
    echo();
    rnv.national_code2 = national_code;
    mvprintw(10, 25, "Type or title of violation : ");
    scanw("%[^\n]%*c", rnv.type);
    mvprintw(13, 25, "Description : ");
    scanw("%[^\n]%*c", rnv.description);
    mvprintw(16, 25, "Place of violation : ");
    scanw("%[^\n]%*c", rnv.placeViolation);
    mvprintw(19, 25, "National code : ");
    scanw("%s", rnv.nationalCode);
    mvprintw(22, 25, "Press Y to set to instant mode.Otherwise press N ");
    noecho();
    while (choice != 'y' && choice != 'n')
        choice = getch();
    switch (choice)
    {
    case 'y':
        rnv.Instant_mode = 1;
        break;
    case 'n':
        rnv.Instant_mode = 0;
        break;
    }
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strcpy(rnv.time, asctime(timeinfo));
    FILE *fp = fopen("Temp3.dat", "a+");
    fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp);
    fclose(fp);
    FILE *fp2 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        rnv.num++;
        FILE *fp3 = fopen("Temp3.dat", "a+");
        fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
        fclose(fp3);
    }
    fclose(fp2);
    rename("Temp3.dat", "Violations.dat");
    create_win3();
    publicSection(national_code);
}

int Edit_reports(long int national_code)
{
    struct RecordNewViolations rnv;
    char choice = 't';
    rnv.num = 1;
    create_win7();
    echo();
    rnv.national_code2 = national_code;
    mvprintw(10, 25, "Type or title of violation : ");
    scanw("%[^\n]%*c", rnv.type);
    mvprintw(13, 25, "Description : ");
    scanw("%[^\n]%*c", rnv.description);
    mvprintw(16, 25, "Place of violation : ");
    scanw("%[^\n]%*c", rnv.placeViolation);
    mvprintw(19, 25, "National code : ");
    scanw("%s", rnv.nationalCode);
    mvprintw(22, 25, "Press Y to set to instant mode.Otherwise press N ");
    noecho();
    while (choice != 'y' && choice != 'n')
        choice = getch();
    switch (choice)
    {
    case 'y':
        rnv.Instant_mode = 1;
        break;
    case 'n':
        rnv.Instant_mode = 0;
        break;
    }
    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strcpy(rnv.time, asctime(timeinfo));
    FILE *fp = fopen("Temp3.dat", "a+");
    fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp);
    fclose(fp);
}

int Related_reports(long int national_code)
{
    int y = 3;
    int t_n_exist = 0;
    char title[20];
    struct RecordNewViolations rnv;
    mvprintw(23, 5, "Type or title of violation : ");
    echo();
    scanw("%[^\n]%*c", title);
    noecho();
    mvprintw(23, 3, "                                         ");
    create_win4();
    FILE *fp1 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp1))
    {
        if (0 == strcmp(title, rnv.type))
        {
            mvprintw(y - 1, 40, "Number : ");
            mvprintw(y - 1, 49, "%d", rnv.num);
            mvprintw(y, 40, "Type or title of violation : ");
            mvprintw(y, 69, "%s", rnv.type);
            mvprintw(y + 2, 40, "Time of registration of the violation : ");
            mvprintw(y + 2, 80, "%s", rnv.time);
            mvprintw(y + 4, 40, "Condition : in progress");
            if (rnv.Instant_mode == 1)
            {
                mvprintw(y + 5, 40, "Instant mode");
            }
            mvprintw(y + 6, 39, "---------------------------------------------------------------------");
            y += 8;
            t_n_exist++;
        }
    }
    fclose(fp1);
    if (t_n_exist == 0)
    {
        create_win3();
        mvprintw(25, 5, "This title does not exist");
        menu_related_reports(national_code);
        return 0;
    }
    mvprintw(25, 3, "                            ");
    menu_related_reports(national_code);
}

int menu_related_reports(long int national_code)
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_related_reports);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_related_reports[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(8, 30, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 27, 3, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("public section", item_name(current_item(my_menu))))
            {
                create_win3();
                publicSection(national_code);
                return 0;
            }
            if (0 == strcmp("View related reports", item_name(current_item(my_menu))))
            {
                Related_reports(national_code);
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int LegalUnit()
{
    mvprintw(2, 40, "  _                              _      _   _           _   _   ");
    mvprintw(3, 40, " | |       ___    __ _    __ _  | |    | | | |  _ __   (_) | |_ ");
    mvprintw(4, 40, " | |      / _ \\  / _` |  / _` | | |    | | | | | '_ \\  | | | __|");
    mvprintw(5, 40, " | |___  |  __/ | (_| | | (_| | | |    | |_| | | | | | | | | |_ ");
    mvprintw(6, 40, " |_____|  \\___|  \\__, |  \\__,_| |_|     \\___/  |_| |_| |_|  \\__|");
    mvprintw(7, 40, "                 |___/                                          ");
    create_win5();
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_LegalUnit);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_LegalUnit[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(10, 28, 12, 60);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 7, 25, 2, 1));
    set_menu_format(my_menu, 6, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */
            if (0 == strcmp("Inbox", item_name(current_item(my_menu))))
            {
                create_win3();
                legal_Inbox();
                return 0;
            }
            if (0 == strcmp("History", item_name(current_item(my_menu))))
            {
                create_win3();
                History(2, 100);
                return 0;
            }
            if (0 == strcmp("Block user", item_name(current_item(my_menu))))
            {
                create_win3();
                Block_user();
                return 0;
            }
            if (0 == strcmp("Encourage the user", item_name(current_item(my_menu))))
            {
                create_win3();
                Encourage_user();
                return 0;
            }
            if (0 == strcmp("Shut down the system", item_name(current_item(my_menu))))
            {
                create_win3();
                shut_down_system();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int legal_Inbox()
{
    int number = 0;
    int y = 3;
    create_win4();
    struct RecordNewViolations rnv;
    struct Register r;
    FILE *fp9 = fopen("Violations2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp9))
    {
        if (rnv.Instant_mode == 1)
        {
            number++;
            rnv.num = number;
            FILE *fp8 = fopen("Temp.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp8);
            fclose(fp8);
        }
        else if (rnv.Instant_mode == 0)
        {
            number++;
            rnv.num = number;
            FILE *fp7 = fopen("Temp2.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp7);
            fclose(fp7);
        }
    }
    FILE *fp6 = fopen("Temp2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp11 = fopen("Temp.dat", "a+");
        fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp11);
        fclose(fp11);
    }
    fclose(fp6);
    fclose(fp9);
    rename("Temp.dat", "Violations2.dat");
    remove("Temp2.dat");
    FILE *fp2 = fopen("Violations2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        mvprintw(y - 1, 40, "Number : ");
        mvprintw(y - 1, 49, "%d", rnv.num);
        FILE *fp19 = fopen("Registered.dat", "a+");
        while (fread(&r, sizeof(struct Register), 1, fp19))
        {
            if (r.national_code == rnv.national_code2)
            {
                mvprintw(y - 1, 60, "User name : ");
                mvprintw(y - 1, 72, "%s", r.user_name);
            }
        }
        fclose(fp19);
        mvprintw(y, 40, "Type or title of violation : ");
        mvprintw(y, 69, "%s", rnv.type);
        mvprintw(y + 2, 40, "Time of registration of the violation : ");
        mvprintw(y + 2, 80, "%s", rnv.time);
        mvprintw(y + 4, 40, "Condition : in progress");
        if (rnv.Instant_mode == 1)
        {
            mvprintw(y + 5, 40, "Instant mode");
        }
        mvprintw(y + 6, 39, "---------------------------------------------------------------------");
        y += 8;
    }
    fclose(fp2);
    menu_legal_inbox();
}

int confirmation()
{
    int num;
    int number2 = 0;
    int confirmation;
    int number = 1;
    int n_incorrect = 0;
    struct RecordNewViolations rnv;
    create_win6();
    mvprintw(16, 123, "Number : ");
    echo();
    scanw("%d", &num);
    FILE *fp2 = fopen("Violations2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (num == rnv.num)
        {
            n_incorrect++;
        }
    }
    if (n_incorrect == 0)
    {
        create_win3();
        mvprintw(22, 115, "The given number is incorrect");
        legal_Inbox();
        return 0;
    }
    fclose(fp2);
    FILE *fp6 = fopen("Violations2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp3 = fopen("Temp3.dat", "a+");
        confirmation = 1;
        if (num == rnv.num)
        {
            time_t rawtime;
            struct tm *timeinfo;

            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strcpy(rnv.time, asctime(timeinfo));
            rnv.ApproveORrejectORsupervisor = 1;
            FILE *fp = fopen("Temp4.dat", "a+");
            rnv.num = number;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp);
            fclose(fp);
            FILE *fp2 = fopen("History.dat", "a+");
            while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
            {
                number++;
                rnv.num = number;
                FILE *fp5 = fopen("Temp4.dat", "a+");
                fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp5);
                fclose(fp5);
            }
            fclose(fp2);
            rename("Temp4.dat", "History.dat");
            confirmation = 0;
        }
        if (confirmation == 1)
        {
            number2++;
            rnv.num = number2;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
            fclose(fp3);
        }
    }
    fclose(fp6);
    rename("Temp3.dat", "Violations2.dat");
    create_win3();
    LegalUnit();
}

int reject()
{
    int num;
    int reject;
    int number2 = 0;
    int number = 1;
    int n_incorrect = 0;
    struct RecordNewViolations rnv;
    create_win6();
    mvprintw(18, 123, "Number : ");
    echo();
    scanw("%d", &num);
    FILE *fp2 = fopen("Violations2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (num == rnv.num)
        {
            n_incorrect++;
        }
    }
    if (n_incorrect == 0)
    {
        create_win3();
        mvprintw(22, 115, "The given number is incorrect");
        legal_Inbox();
        return 0;
    }
    fclose(fp2);
    FILE *fp6 = fopen("Violations2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp3 = fopen("Temp3.dat", "a+");
        reject = 1;
        if (num == rnv.num)
        {
            mvprintw(20, 110, "Reason for rejecting the report : ");
            mvscanw(21, 110, "%[^\n]%*c", rnv.rejectReport);

            time_t rawtime;
            struct tm *timeinfo;

            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strcpy(rnv.time, asctime(timeinfo));
            rnv.ApproveORrejectORsupervisor = 0;
            FILE *fp = fopen("Temp4.dat", "a+");
            rnv.num = number;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp);
            fclose(fp);
            FILE *fp2 = fopen("History.dat", "a+");
            while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
            {
                number++;
                rnv.num = number;
                FILE *fp5 = fopen("Temp4.dat", "a+");
                fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp5);
                fclose(fp5);
            }
            fclose(fp2);
            rename("Temp4.dat", "History.dat");
            reject = 0;
        }
        if (reject == 1)
        {
            number2++;
            rnv.num = number2;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
            fclose(fp3);
        }
    }
    fclose(fp6);
    rename("Temp3.dat", "Violations2.dat");
    create_win3();
    LegalUnit();
}

int menu_legal_inbox()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_legal_inbox);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_legal_inbox[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(9, 26, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 20, 3, 3));
    set_menu_format(my_menu, 3, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Legal Unit", item_name(current_item(my_menu))))
            {
                create_win3();
                LegalUnit();
                return 0;
            }
            if (0 == strcmp("Confirmation", item_name(current_item(my_menu))))
            {
                confirmation();
                return 0;
            }
            if (0 == strcmp("Reject", item_name(current_item(my_menu))))
            {
                reject();
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Block_user()
{
    int y = 8;
    int y2 = 8;
    mvprintw(3, 51, "Registered");
    refresh();
    mvprintw(3, 95, "blocked");
    refresh();
    create_win8();
    struct Register r;
    FILE *fp9 = fopen("Blocked.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp9))
    {
        mvprintw(y2 - 1, 82, "user name : ");
        mvprintw(y2 - 1, 94, "%s", r.user_name);
        mvprintw(y2 + 1, 81, "--------------------------------------");
        y2 += 4;
        refresh();
    }
    fclose(fp9);
    FILE *fp = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp))
    {
        mvprintw(y - 1, 40, "user name : ");
        mvprintw(y - 1, 52, "%s", r.user_name);
        mvprintw(y + 1, 39, "--------------------------------------");
        y += 4;
        refresh();
    }
    fclose(fp);
    menu_block_user();
}

int block_user2()
{
    int un_n_found = 0;
    char username[30];
    struct Register r;
    mvprintw(22, 7, "user name : ");
    echo();
    scanw("%s", username);
    FILE *fp4 = fopen("Blocked.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp4))
    {
        if (0 == strcmp(username, r.user_name))
        {
            create_win3();
            mvprintw(21, 4, "The user is blocked");
            Block_user();
        }
    }
    fclose(fp4);
    FILE *fp2 = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp2))
    {
        if (0 == strcmp(username, r.user_name))
        {
            FILE *fp3 = fopen("Blocked.dat", "a+");
            fwrite(&r, sizeof(struct Register), 1, fp3);
            fclose(fp3);
            un_n_found = 1;
        }
    }
    fclose(fp2);
    if (un_n_found == 0)
    {
        create_win3();
        mvprintw(21, 8, "Username not found");
        Block_user();
    }
    create_win3();
    LegalUnit();
}

int menu_block_user()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_block_user);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_block_user[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(8, 26, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 20, 3, 3));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Legal Unit", item_name(current_item(my_menu))))
            {
                create_win3();
                LegalUnit();
                return 0;
            }
            if (0 == strcmp("block user", item_name(current_item(my_menu))))
            {
                block_user2();
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Encourage_user()
{
    int y = 4;
    create_win4();
    struct Register r;
    FILE *fp = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp))
    {
        mvprintw(y - 1, 62, "user name : ");
        mvprintw(y - 1, 74, "%s", r.user_name);
        mvprintw(y + 1, 39, "--------------------------------------------------------------------");
        y += 4;
        refresh();
    }
    fclose(fp);
    menu_encourage_user();
}

int Encourage_user2()
{
    int un_n_found = 0;
    int Incentive_money2;
    char username[30];
    struct Register r;
    mvprintw(22, 7, "user name : ");
    echo();
    scanw("%s", username);
    FILE *fp2 = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp2))
    {
        if (0 == strcmp(username, r.user_name))
        {
            mvprintw(24, 3, "The amount of incentive money($) : ");
            mvscanw(25, 5, "%d", &Incentive_money2);
            r.Incentive_money = r.Incentive_money + Incentive_money2;
            un_n_found = 1;
            FILE *fp5 = fopen("temp.dat", "a+");
            fwrite(&r, sizeof(struct Register), 1, fp5);
            fclose(fp5);
        }
        else
        {
            FILE *fp7 = fopen("temp.dat", "a+");
            fwrite(&r, sizeof(struct Register), 1, fp7);
            fclose(fp7);
        }
    }
    fclose(fp2);
    rename("temp.dat", "Registered.dat");
    if (un_n_found == 0)
    {
        create_win3();
        mvprintw(21, 8, "Username not found");
        Encourage_user();
    }
    create_win3();
    LegalUnit();
}

int menu_encourage_user()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_encourage_user);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_encourage_user[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(8, 26, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 21, 3, 2));
    set_menu_format(my_menu, 2, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Legal Unit", item_name(current_item(my_menu))))
            {
                create_win3();
                LegalUnit();
                return 0;
            }
            if (0 == strcmp("Encourage the user", item_name(current_item(my_menu))))
            {
                Encourage_user2();
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Supervisor_section()
{
    mvprintw(2, 15, "  ____                                          _                            ____                  _     _                 ");
    mvprintw(3, 15, " / ___|   _   _   _ __     ___   _ __  __   __ (_)  ___    ___    _ __      / ___|    ___    ___  | |_  (_)   ___    _ __  ");
    mvprintw(4, 15, " \\___ \\  | | | | | '_ \\   / _ \\ | '__| \\ \\ / / | | / __|  / _ \\  | '__|     \\___ \\   / _ \\  / __| | __| | |  / _ \\  | '_ \\ ");
    mvprintw(5, 15, "  ___) | | |_| | | |_) | |  __/ | |     \\ V /  | | \\__ \\ | (_) | | |         ___) | |  __/ | (__  | |_  | | | (_) | | | | |");
    mvprintw(6, 15, " |____/   \\__,_| | .__/   \\___| |_|      \\_/   |_| |___/  \\___/  |_|        |____/   \\___|  \\___|  \\__| |_|  \\___/  |_| |_|");
    mvprintw(7, 15, "                 |_|                                                                                                       ");
    create_win5();
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_Supervisor_section);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_Supervisor_section[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(10, 28, 12, 60);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 20, 3, 7));
    set_menu_format(my_menu, 3, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Inbox", item_name(current_item(my_menu))))
            {
                create_win3();
                Supervisor_inbox();
                return 0;
            }
            if (0 == strcmp("History", item_name(current_item(my_menu))))
            {
                create_win3();
                History(3, 200);
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Supervisor_inbox()
{
    int number = 0;
    int y = 3;
    create_win4();
    struct RecordNewViolations rnv;
    struct Register r;
    FILE *fp9 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp9))
    {
        if (rnv.Instant_mode == 1)
        {
            number++;
            rnv.num = number;
            FILE *fp8 = fopen("Temp.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp8);
            fclose(fp8);
        }
        else if (rnv.Instant_mode == 0)
        {
            number++;
            rnv.num = number;
            FILE *fp7 = fopen("Temp2.dat", "a+");
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp7);
            fclose(fp7);
        }
    }
    FILE *fp6 = fopen("Temp2.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp11 = fopen("Temp.dat", "a+");
        fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp11);
        fclose(fp11);
    }
    fclose(fp6);
    fclose(fp9);
    rename("Temp.dat", "Violations.dat");
    remove("Temp2.dat");
    FILE *fp2 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        mvprintw(y - 1, 40, "Number : ");
        mvprintw(y - 1, 49, "%d", rnv.num);
        FILE *fp19 = fopen("Registered.dat", "a+");
        while (fread(&r, sizeof(struct Register), 1, fp19))
        {
            if (r.national_code == rnv.national_code2)
            {
                mvprintw(y - 1, 60, "User name : ");
                mvprintw(y - 1, 72, "%s", r.user_name);
            }
        }
        fclose(fp19);
        mvprintw(y, 40, "Type or title of violation : ");
        mvprintw(y, 69, "%s", rnv.type);
        mvprintw(y + 2, 40, "Time of registration of the violation : ");
        mvprintw(y + 2, 80, "%s", rnv.time);
        mvprintw(y + 4, 40, "Condition : in progress");
        if (rnv.Instant_mode == 1)
        {
            mvprintw(y + 5, 40, "Instant mode");
        }
        mvprintw(y + 6, 39, "---------------------------------------------------------------------");
        y += 8;
    }
    fclose(fp2);
    menu_Supervisor_inbox();
}

int menu_Supervisor_inbox()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_Supervisor_inbox);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_Supervisor_inbox[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(9, 26, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 21, 3, 2));
    set_menu_format(my_menu, 3, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Supervisor section", item_name(current_item(my_menu))))
            {
                create_win3();
                Supervisor_section();
                return 0;
            }
            if (0 == strcmp("Confirmation", item_name(current_item(my_menu))))
            {
                confirmation2();
                return 0;
            }
            if (0 == strcmp("Reject", item_name(current_item(my_menu))))
            {
                reject2();
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int confirmation2()
{
    int num;
    int number2 = 0;
    int confirmation;
    int number = 1;
    int n_incorrect = 0;
    struct RecordNewViolations rnv;
    create_win6();
    mvprintw(16, 123, "Number : ");
    echo();
    scanw("%d", &num);
    FILE *fp2 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (num == rnv.num)
        {
            n_incorrect++;
        }
    }
    if (n_incorrect == 0)
    {
        create_win3();
        mvprintw(22, 115, "The given number is incorrect");
        Supervisor_inbox();
        return 0;
    }
    fclose(fp2);
    FILE *fp6 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp3 = fopen("Temp3.dat", "a+");
        confirmation = 1;
        if (num == rnv.num)
        {
            time_t rawtime;
            struct tm *timeinfo;

            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strcpy(rnv.time, asctime(timeinfo));
            //rnv.ApproveORreject = 1;
            FILE *fp = fopen("Temp4.dat", "a+");
            rnv.num = number;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp);
            fclose(fp);
            FILE *fp2 = fopen("Violations2.dat", "a+");
            while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
            {
                number++;
                rnv.num = number;
                FILE *fp5 = fopen("Temp4.dat", "a+");
                fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp5);
                fclose(fp5);
            }
            fclose(fp2);
            rename("Temp4.dat", "Violations2.dat");
            confirmation = 0;
        }
        if (confirmation == 1)
        {
            number2++;
            rnv.num = number2;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
            fclose(fp3);
        }
    }
    fclose(fp6);
    rename("Temp3.dat", "Violations.dat");
    create_win3();
    Supervisor_section();
}

int reject2()
{
    int num;
    int reject;
    int number2 = 0;
    int number = 1;
    int n_incorrect = 0;
    struct RecordNewViolations rnv;
    create_win6();
    mvprintw(18, 123, "Number : ");
    echo();
    scanw("%d", &num);
    FILE *fp2 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
    {
        if (num == rnv.num)
        {
            n_incorrect++;
        }
    }
    if (n_incorrect == 0)
    {
        create_win3();
        mvprintw(22, 115, "The given number is incorrect");
        Supervisor_inbox();
        return 0;
    }
    fclose(fp2);
    FILE *fp6 = fopen("Violations.dat", "a+");
    while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp6))
    {
        FILE *fp3 = fopen("Temp3.dat", "a+");
        reject = 1;
        if (num == rnv.num)
        {
            time_t rawtime;
            struct tm *timeinfo;

            time(&rawtime);
            timeinfo = localtime(&rawtime);
            strcpy(rnv.time, asctime(timeinfo));
            rnv.ApproveORrejectORsupervisor = 2;
            FILE *fp = fopen("Temp4.dat", "a+");
            rnv.num = number;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp);
            fclose(fp);
            FILE *fp2 = fopen("History.dat", "a+");
            while (fread(&rnv, sizeof(struct RecordNewViolations), 1, fp2))
            {
                number++;
                rnv.num = number;
                FILE *fp5 = fopen("Temp4.dat", "a+");
                fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp5);
                fclose(fp5);
            }
            fclose(fp2);
            rename("Temp4.dat", "History.dat");
            reject = 0;
        }
        if (reject == 1)
        {
            number2++;
            rnv.num = number2;
            fwrite(&rnv, sizeof(struct RecordNewViolations), 1, fp3);
            fclose(fp3);
        }
    }
    fclose(fp6);
    rename("Temp3.dat", "Violations.dat");
    create_win3();
    Supervisor_section();
}

int shut_down_system()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_shut_down_system);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_shut_down_system[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(7, 26, 13, 6);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 21, 2, 2));
    set_menu_format(my_menu, 3, 1);
    set_menu_mark(my_menu, " * ");

    box(my_menu_win, 0, 0);
    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("Legal Unit", item_name(current_item(my_menu))))
            {
                create_win3();
                LegalUnit();
                return 0;
            }
            if (0 == strcmp("Shut down", item_name(current_item(my_menu))))
            {
                Shut_down();
                return 0;
            }
            if (0 == strcmp("opening", item_name(current_item(my_menu))))
            {
                opening();
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

int Shut_down()
{
    echo();
    struct Time ti;
    struct EpochTime e;
    struct tm t;
    time_t t_of_day;
    create_win4();
    mvprintw(4, 65, "-< From >-");
    mvprintw(8, 65, "Day : ");
    scanw("%d", &ti.day);
    mvprintw(10, 65, "Hour : ");
    scanw("%d", &ti.hour);
    t.tm_year = 2021 - 1900;
    t.tm_mon = 1;
    t.tm_mday = ti.day;
    t.tm_hour = ti.hour;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;
    t_of_day = mktime(&t);
    e.epoch1 = t_of_day;
    mvprintw(18, 65, "-< Until >-");
    mvprintw(22, 65, "Day : ");
    scanw("%d", &ti.day);
    mvprintw(24, 65, "Hour : ");
    scanw("%d", &ti.hour);
    t.tm_year = 2021 - 1900;
    t.tm_mon = 1;
    t.tm_mday = ti.day;
    t.tm_hour = ti.hour;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;
    t_of_day = mktime(&t);
    e.epoch2 = t_of_day;
    FILE *fp2 = fopen("Time.dat", "a+");
    fwrite(&e, sizeof(struct EpochTime), 1, fp2);
    fclose(fp2);
    create_win3();
    LegalUnit();
}

int opening()
{
    remove("Time.dat");
    create_win3();
    LegalUnit();
}

int Forgot_password()
{
    struct Register r;
    long int national_code;
    create_win2();
    echo();
    mvprintw(16, 55, "Enter the national code : ");
    scanw("%ld" , &national_code);
    FILE *fp3 = fopen("Registered.dat", "a+");
    while (fread(&r, sizeof(struct Register), 1, fp3))
    {
        if (r.national_code == national_code)
        {
            mvprintw(23, 60, "Login completed successfully");
            menu_public_login2(r.national_code);
            return 0;
        }
    }
    fclose(fp3);
    mvprintw(22, 58, "The national code is incorrect");
    menu_public_login3();

}

int menu_public_login3()
{
    ITEM **my_items;
    int c;
    MENU *my_menu;
    int n_choices, i;
    WINDOW *my_menu_win;
    noecho();
    keypad(stdscr, TRUE);
    n_choices = ARRAY_SIZE(ch_public_login3);
    my_items = (ITEM **)calloc(n_choices + 1, sizeof(ITEM *));
    for (i = 0; i < n_choices; ++i)
        my_items[i] = new_item(ch_public_login3[i], NULL);

    my_items[n_choices] = (ITEM *)NULL;

    my_menu = new_menu((ITEM **)my_items);

    menu_opts_off(my_menu, O_ONEVALUE);

    my_menu_win = newwin(4, 31, 23, 62);
    keypad(my_menu_win, TRUE);

    set_menu_win(my_menu, my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 4, 20, 0, 3));
    set_menu_format(my_menu, 4, 1);
    set_menu_mark(my_menu, " * ");

    wrefresh(my_menu_win);
    post_menu(my_menu);
    wrefresh(my_menu_win);
    refresh();

    while ((c = wgetch(my_menu_win)))
    {
        switch (c)
        {
        case KEY_DOWN:
            menu_driver(my_menu, REQ_DOWN_ITEM);
            break;
        case KEY_UP:
            menu_driver(my_menu, REQ_UP_ITEM);
            break;
        case 10: /* Enter */

            if (0 == strcmp("register page", item_name(current_item(my_menu))))
            {
                create_win2();
                Register();
                return 0;
            }
            if (0 == strcmp("re-login", item_name(current_item(my_menu))))
            {
                create_win2();
                Login();
                return 0;
            }
            if (0 == strcmp("Forgot password", item_name(current_item(my_menu))))
            {
                create_win2();
                Forgot_password();
                return 0;
            }
            if (0 == strcmp("Exit", item_name(current_item(my_menu))))
            {
                return 0;
            }
            pos_menu_cursor(my_menu);
            break;
        }
    }
}

