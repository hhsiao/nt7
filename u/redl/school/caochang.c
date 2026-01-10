// This program is a part of NITAN MudLIB
// redl 2013/8
#include <ansi.h>
#include <room.h>
inherit ROOM;

#define BONUS_EXP 36000
#define BONUS_IMPROVE_SKILL 10000

int clean_up(int inherited) { return 1;}

void create()
{
        set("short", "學堂操場");
        set("long",
"操場的前方高高聳立著一根銀白色的旗杆，旗杆的頂端是一面鮮豔的\n"
"五星紅旗，襯著藍天，映著白雲，顯得更加莊嚴。操場旁邊有個小池塘，\n"
"四周綠樹環繞，野花遍地……\n");
                set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "south" : __DIR__"gate",
                        "north" : __DIR__"jiaoshi",
                ]));

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1);
        set("no_sleep_room", 1);

        setup();
}


int filter_skill(string sk, object me)
{
        if (!me->can_improve_skill(sk)) return 0;
        if (SKILL_D(sk)->type() != "martial") return 0;
        return 1;
}

int do_giftbaby(object me, string msg, int p)
{
        int r;
        r = BONUS_EXP + random(BONUS_EXP/10);
        if (!p) p = 100;
        r = r * p / 100;
        call_other(GIFT_D, "bonus", me, ([ "exp":r, "pot":r/3, "prompt":"你在"+msg]));
        addn("experience", r/10, me);
        message_vision(NOR + "$N" + HIG + "在" + msg + "獲得了" + chinese_number(r) + "點經驗、" + chinese_number(r/3) + "點潛能、" + chinese_number(r/10) + "點體會。\n" + NOR, me);
        return 1;
}

int do_giftbaby2(object me, string msg, int p)
{
        int r, lv, imp;
        string *ks;
        lv = query("level", me);
        if (lv < 1) lv = 1;
        if (lv > 100) lv = 100;
        imp = (BONUS_IMPROVE_SKILL + random(BONUS_IMPROVE_SKILL/10)) * lv / 5;
        if (!p) p = 100;
        imp = imp * p / 100;
                                if (!me->query_skills() || !sizeof(me->query_skills())) {
                                        me->improve_skill("dodge", 1000);
                                        me->improve_skill("force", 1000);
                                        me->improve_skill("parry", 1000);
                                        me->improve_skill("unarmed", 1000);
                                        me->improve_skill("cuff", 1000);
                                        me->improve_skill("hand", 1000);
                                        me->improve_skill("claw", 1000);
                                        me->improve_skill("strike", 1000);
                                }
                        ks = filter_array(keys(me->query_skills()), (: filter_skill :), me);
                        if (r = sizeof(ks))
                        {
                                r = random(r);
                                me->improve_skill(ks[r], imp);
                                message_vision(NOR + "$N" + HIG + "在" + msg + "對「" + to_chinese(ks[r]) + "」有所感悟。\n" + NOR, me);
                        }
        return 1;
}

void do_rndmove(object baby, string str)
{
        object room;

        if (!baby || !objectp(baby)) return;
        room = environment(baby);
        if (!room || base_name(room)!=str) return;
        if (!query_temp("school/init", baby)) return;

        if (baby->is_busy()) {
                call_out("do_rndmove", 2, baby, str);
                return;
        }

        delete_temp("school/init", baby);

        if (!random(5)) {
                if (!random(25)) {
                        baby->command("go north");
                } else {
                        baby->command("go south");
                }
                return;
        } else {
                switch (random(10)) {
                        case 0:
                                message_vision(CYN + "$N" + CYN + "噗通~~一聲跳進池塘裡去了，半餉冒出頭游上岸，手裡抓了條大鯉魚。\n" + NOR, baby);
                                if (query_temp("school/play", baby)<10) {
                                        addn_temp("school/play", 3 + random(2), baby);
                                        break;
                                }
                                set_temp("school/play", 1, baby);
                                do_giftbaby(baby, "遊戲過程中", 100);
                                break;
                        case 1:
                                message_vision(CYN + "$N" + CYN + "拿出一把小刀在地上撬呀撬，居然挖出一窩螞蟻蛋來。\n" + NOR, baby);
                                if (query_temp("school/play", baby)<13) {
                                        addn_temp("school/play", 3 + random(2), baby);
                                        break;
                                }
                                set_temp("school/play", 1, baby);
                                do_giftbaby2(baby, "遊戲過程中", 100);
                                break;
                        case 2:
                                baby->command("ruffle 皮球");
                                addn_temp("school/play", 1, baby);
                                break;
                        case 3:
                                baby->command("zaocao");
                                addn_temp("school/play", 1, baby);
                                break;
                        case 4:
                                baby->command("roll2");
                                addn_temp("school/play", 1 + random(2), baby);
                                break;
                        case 5:
                                baby->command("jump " + query("id", baby));
                                addn_temp("school/play", 1 + random(2), baby);
                                break;
                        case 6:
                                baby->command("roll " + query("id", baby) + " 屁股");
                                addn_temp("school/play", 1 + random(2), baby);
                                break;
                        case 7:
                                message_vision(CYN + "$N" + CYN + "像猴子一樣順著旗杆爬了上去，又快速夾緊雙腿滑下來大喊道：好爽，好爽..\n" + NOR, baby);
                                addn_temp("school/play", 3 + random(2), baby);
                                break;
                        case 8:
                                message_vision(CYN + "$N" + CYN + "像猴子一樣順著旗杆爬了上去，在旗杆頂上掏出一個鳥蛋，OMG...\n" + NOR, baby);
                                addn_temp("school/play", 3 + random(2), baby);
                                break;
                        default:
                                baby->command("think 我下一步該玩什麼呢？");
                                break;
                }

                set_temp("school/init", 1, baby);
                call_out("do_rndmove", 8 + random(2), baby, str);
        }
}

void init()
{
        object ob = this_player();
        if (base_name(ob)=="/clone/user/baby") {
                ob->command("halt");
                ob->command("think 我下一步該玩什麼呢？");

                set_temp("school/init", 1, ob);
                call_out("do_rndmove", random(6) + 10, ob, base_name(this_object()));
        }
}

int valid_leave(object me, string dir)
{
        if (!playerp(me) && dir == "north") {
                if (base_name(me)!="/clone/user/baby") {
                        me->start_busy(35+random(26));
                        return 0;
                }

                if (!query_temp("school/pay", me)) {
                        me->start_busy(random(6) + 10);
                        message_vision(YEL "看門大叔氣喘吁吁地跑過來一把拉住$N" YEL "道：慢著，叫你父母來繳了學費再去教室上課...\n" NOR, me);
                        set_temp("school/init", 1, me);
                        call_out("do_rndmove", 2, me, base_name(this_object()));
                        return 0;
                }
        }

        return ::valid_leave(me, dir);
}
