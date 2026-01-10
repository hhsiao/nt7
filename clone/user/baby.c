// This program is a part of NITAN MudLIB
// redl 2013/10
// /clone/user/baby.c
#include <ansi.h>
inherit BABY;
inherit F_NOCLONE;

#define BABYDTC "/d/dongtian/create_d.c"
#define BABYSCH "/u/redl/school/gate"
#define GETAGE 60

void consider();
void provide();
mixed ask_father();
mixed ask_mother();
int check_legal_name(string name, int max_len);
mixed get_pob();

int is_baby(){ return 1; }

void add_work(int hour, string act, string cact, object parent) {
    set_temp("dis_all_cmd/time", time() + hour * 3600);
    set_temp("dis_all_cmd/act", act);
    set_temp("dis_all_cmd/cact", cact);
    set_temp("dis_all_cmd/officer", parent);
    set("chat_chance_bak", query("chat_chance"));
    set("chat_chance", 80);
    save();
    this_object()->reset_action();
}

void remove(string euid) {
    if(is_fighting() ) remove_all_enemy(1);
    save();
}

// override set function
varargs mixed set(string idx, mixed para, object ob)
{
    int i, j, lvl, level;

    if(!ob ) ob = this_object();

    if (idx == "combat_exp" && para)
    {
        if (para > (int)query("combat_exp")) {
            level = (int)query("level");
            if (! level || level < 1) level = 1;

            for (i = level;;i++) {
                if ((i + 1) * (i + 1) * (i + 1) > (para / 10000))
                {
                    lvl = i;
                    break;
                }
            }

            if (lvl > level)
            {
                j = lvl - level;
                set("level", lvl);
                addn("points", 4 * j);
                addn("improve/int", j);
                addn("improve/str", j);
                addn("improve/con", j);
                addn("improve/dex", j);
                addn("experience", 20 * j);
                addn("potential", 200 * j);
                addn("magic_points", 20 * j);
                tell_object(ob, HIY "只見一道紅光飛進你的體內，你的人物等級提升了！\n" +
                    "此次升級，你獲得了" + chinese_number(4 * j) +
                    "點技能點、" + chinese_number(200 * j) +
                    "點潛能、" + chinese_number(20 * j) +
                    "點實戰體會和" + chinese_number(20 * j) +
                    "點靈慧！\n" NOR);
            }
        }
        return set_db(idx, para);
    } else
    return set_db(idx, para);
}
// override add function by Lonely
varargs mixed addn(string prop, mixed data, object ob)
{
    mixed old;

    if(!ob ) ob = this_object();

    if (prop == "combat_exp")
    {
        if (! (old = query(prop)))
            return set(prop, data);

        return set(prop, old + data);
    } else
    return ::addn(prop, data, ob);
}

int clean_up(int inherited) { return 1;}

void create() {
    set_name("寶寶", ({ "xiao baobao", "baby" }) );
    set("long", NOR
        "一個白白拚胖的乖寶寶，不知道是誰家的孩子。\n" NOR
    );
    set("gender", (random(2) ? "男性" : "女性"));
    set("age", 1);
    set("attitude", "friendly");
    set("no_clean_up", 1);
    set("env/halt_age", 1);
    set("combat_exp", 10000);
    set("born", 1);     // human.c調用

    setup();
    carry_object("/clone/cloth/cloth")->wear();

    remove_call_out("check_me");
    call_out("check_me", 2, this_object());
}

void check_me(object me) {
    if(me && !mapp(query("parents", me)) )
        destruct(me);
    return;
}

int load_baby(object me) {
    string file;
    int max_qi, max_jing;

    if (! userp(me)) return 0;

    if(query("gender", me) == "女性" )
        file = "/data/baby/" + query("id", me) + ".o";
    else
        if(query("couple/couple_id", me) )
        file = "/data/baby/" + query("couple/couple_id", me) + ".o";

    if (! file || file_size(file) < 0) return 0;

    if (stringp(read_file(file)))
    {
        restore_object(file);
        reset_action();

        max_qi = query("max_neili") / 2 + query("drug_addqi");
        if(query("breakup") ) max_qi += max_qi * 2;
        max_jing = query("max_jingli") / 3 + query("drug_addjing");
        if(query("breakup") ) max_jing += max_jing;
        if(query("animaout") ) max_jing += max_jing;
        if(max_qi > query("max_qi") )
            set("max_qi", max_qi);
        if(max_jing > query("max_jing") )
            set("max_jing", max_jing);
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));

        set_name(query("name"), ({query("id"), "baby"}));

        set("chat_chance", query("int") / 10 + 3);
        set("chat_chance_combat", query("con") * 2 + 5);

        set("chat_msg", ({
            (: consider :),
            (: provide :)
        }));

        set("inquiry", ([
            "父親" : (: ask_father :),
            "爹爹" : (: ask_father :),
            "爸爸" : (: ask_father :),
            "母親" : (: ask_mother :),
            "媽媽" : (: ask_mother :)
            ]));

        set("perform_skills", 0);

        setup();

        UPDATE_D->check_user(this_object());
        remove_call_out("consider");
        call_out("consider", 10);
        set("long", NOR + "一個白白拚胖的乖寶寶。\n" + HIK + "( 指令有：kill|get|drop|cha|whisper|home_baby|nick_baby|name_baby|fangqi_sk|youli )\n" + NOR);
        set("auto_perform", 1);
    } else
    return 0;
}

int do_fangqi(string arg) {
    object ob = this_object();
    object me = this_player();
    int lv;

    if(query("parents/father") != query("id", me) &&
        query("parents/mother") != query("id", me) )
        return notify_fail("看清楚了，他可不是你的孩子！\n");

    if (! arg)
        return notify_fail("你要替孩子放棄什麼技能？\n");


    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(me, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    lv = ob->query_skill(arg, 1);
    if (! lv)
        return notify_fail("你的孩子並不會這項技能。\n");

    SKILLS_D->remove_id_from_abandon(ob, arg);
    ob->delete_skill(arg);
    ob->reset_action();
    ob->save();
    ob->start_busy(2);

    ob->command("say 我已經把『" + to_chinese(arg) + "』忘記了。");
    ob->command("cat " + query("id", me));
    //write("你叫孩子放棄了這項技能。\n");
    return 1;
}

int do_youli(string arg) {
    object where, me = this_object(), who = this_player();
    int i, hour;
    string spa, *pa;

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(who, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    if (! arg) {
        //return notify_fail("遊歷，指令格式<youli 難度數 小時數>\n");
        return notify_fail("讓孩子去遊歷，指令格式<youli 小時數>，選擇寬闊的區域才有好的收穫。\n" + NOR);
    }

    if(!(query("id", who) == query("parents/father" ) || query("id", who) == query("parents/mother")) )
    {
        return notify_fail("看清楚了，他可不是你的孩子！\n" + NOR);
    }

    //if (sscanf(arg, "%d %d", diff, hour) != 2) {
    //return notify_fail("遊歷，指令格式<youli 難度數 小時數>\n");
    if (sscanf(arg, "%d", hour) != 1) {
        return notify_fail("讓孩子去遊歷，指令格式<youli 小時數>，選擇寬闊的區域才有好的收穫。\n" + NOR);
    }

    /*
     * if (diff < 1 || diff > 2) {
     * return notify_fail("難度數必須選擇1至2之間。\n");
     * }*/

    if (hour < 1 || hour > 120) {
        return notify_fail("小時數必須選擇1至120之間。\n" + NOR);
    }

    where = environment(me);
    if (!where || !objectp(where) || !where->is_room()) {
        return notify_fail("你必須把孩子放到地上他才能遊歷。\n" + NOR);
    }

    set("youli/start_room", base_name(where));
    pa = explode(query("youli/start_room"), "/");
    if (!pa || undefinedp(pa) || sizeof(pa) < 3 ||
        pa[0]!="d"  || pa[1]=="dongtian" ||
        query("no_fight", where) || query("no_kill", where) || query("sleep_room", where)) {
        me->command("say 這是什麼地方啊？我不想在這裡玩。");
        return notify_fail("看來你的孩子不喜歡從這裡開始。\n" + NOR);
    }

    spa = "/";
    for (i = 0; i < sizeof(pa) -1; i++) {
        spa += pa[i] + "/";
    }
    set("youli/area_path", spa);
    pa = explode(spa, "/");
    spa = pa[sizeof(pa) - 1];
    //write(NOR + "spa:"+spa+"\n" + NOR);
    if (BABYDTC->is_dongtianarea(spa)) set("youli/dongtian_dir", spa);
    else delete("youli/dongtian_dir");

    //dual explode(base_name(environment(me)), "/")
    //dual "/cmds/std/look.c"->locate(base_name(environment(me)))

    message_vision(NOR + CYN + "$N" + NOR + CYN + "對著$n" + NOR + CYN + "輕聲說道：你自己遊歷一番可好？\n" + NOR, who, me);
    message_vision(NOR + CYN + "$n" + NOR + CYN + "嘻嘻一笑道：好的，我就在這"+"/cmds/std/look.c"->locate(base_name(environment(me))) + "探索。\n" + NOR, who, me);
    write("你的孩子開始遊歷冒險了，中途會向在線的你報告收穫，無法反悔。\n" + NOR);
    add_work(hour, "youli", "遊歷", who);
    return 1;
}


void init() {
    add_action("do_kill", ({"kill", "fight", "hit", "steal"}));
    add_action("do_get", "get");
    add_action("do_drop", "drop");
    add_action("do_home", "home_baby");
    add_action("do_nick", "nick_baby");
    add_action("do_changename", "name_baby");
    add_action("do_fangqi", "fangqi_sk");
    add_action("do_youli", "youli");
}

int do_nick(string arg) {
    object ob = this_object();
    object me = this_player();

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(me, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    if(query("parents/father") != query("id", me) &&
        query("parents/mother") != query("id", me) )
        return notify_fail("看清楚了，他可不是你的孩子！\n");

    if (! arg)
        return notify_fail("你要替孩子取什麼綽號？\n");

    if (arg == "none")
    {
        delete("nickname");
        write("你的孩子綽號取消了。\n");
        ob->save();
        return 1;
    }

    if (strlen(arg) > 80)
        return notify_fail("你為孩子取的綽號佔用的資源過多，請重新設置。\n");

    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);

    if (strlen(filter_color(arg)) > 30)
        return notify_fail("你為孩子取的綽號太長了，想一個短一點的、響亮一點的。\n");

    set("nickname", arg + NOR, ob);
    ob->save();
    write("你為孩子取好了綽號。\n");
    return 1;
}

int do_changename(string arg) {
    object ob = this_object();
    object me = this_player();
    string arg_old;

    if(query("parents/father") != query("id", me) &&
        query("parents/mother") != query("id", me) )
        return notify_fail("看清楚了，他可不是你的孩子！\n");

    if (! arg)
        return notify_fail("你要替孩子取什麼名字？\n");

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(me, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }
    arg_old = arg;

    arg = replace_string(arg, "$BLK$", "");
    arg = replace_string(arg, "$RED$", "");
    arg = replace_string(arg, "$GRN$", "");
    arg = replace_string(arg, "$YEL$", "");
    arg = replace_string(arg, "$BLU$", "");
    arg = replace_string(arg, "$MAG$", "");
    arg = replace_string(arg, "$CYN$", "");
    arg = replace_string(arg, "$WHT$", "");
    arg = replace_string(arg, "$HIR$", "");
    arg = replace_string(arg, "$HIG$", "");
    arg = replace_string(arg, "$HIY$", "");
    arg = replace_string(arg, "$HIB$", "");
    arg = replace_string(arg, "$HIM$", "");
    arg = replace_string(arg, "$HIC$", "");
    arg = replace_string(arg, "$HIW$", "");
    arg = replace_string(arg, "$NOR$", "");

    if (! check_legal_name(arg, 8))
        return notify_fail("請重新設定你的孩子名字！\n");

    arg = arg_old;

    arg = replace_string(arg, "$BLK$", BLK);
    arg = replace_string(arg, "$RED$", RED);
    arg = replace_string(arg, "$GRN$", GRN);
    arg = replace_string(arg, "$YEL$", YEL);
    arg = replace_string(arg, "$BLU$", BLU);
    arg = replace_string(arg, "$MAG$", MAG);
    arg = replace_string(arg, "$CYN$", CYN);
    arg = replace_string(arg, "$WHT$", WHT);
    arg = replace_string(arg, "$HIR$", HIR);
    arg = replace_string(arg, "$HIG$", HIG);
    arg = replace_string(arg, "$HIY$", HIY);
    arg = replace_string(arg, "$HIB$", HIB);
    arg = replace_string(arg, "$HIM$", HIM);
    arg = replace_string(arg, "$HIC$", HIC);
    arg = replace_string(arg, "$HIW$", HIW);
    arg = replace_string(arg, "$NOR$", NOR);

    set("name", arg + NOR, ob);
    ob->save();
    write("你為孩子取好了姓名。\n");
    return 1;
}

int check_legal_name(string name, int max_len) {
    int i;

    i = strlen(name);
    if ((strlen(name) < 4) || (strlen(name) > max_len ))
    {
        write(sprintf("對不起，姓名必須是 2 到 %d 箇中文字。\n",
            max_len / 2));
        return 0;
    }

    if (max_len < 13 && strsrch(NAME_D->who_is(name), "泥") >= 0)
    {
        write("對不起，孩子的名字不能和玩家的名字重複。\n");
        return 0;
    }

    if (max_len < 13 && ! is_chinese(name))
    {
        write("對不起，請您用「中文」為孩子取名字或描述。\n");
        return 0;
    }
    return 1;
}

int do_home(string arg) {
    object me = this_object(), who = this_player();

    if (! arg) return 0;
    if (! this_object()->id(arg)) return 0;

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(who, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    if(query("id", who) == query("parents/father" )
        || query("id", who) == query("parents/mother") )
    {
        message_vision("$N對著$n輕聲說道：現在我有些事情，你先回家去吧。\n", who, me);
        me->save();
        destruct(me);
        return 1;
    } else
    command("say 你是誰啊，為什麼要聽你的話？\n");
    return 1;
}

int do_drop(string arg) {
    object me = this_object(), who = this_player();

    if (! arg || ! this_object()->id(arg)) return 0;

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(who, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    if (! present(query("id", me), who))
        return notify_fail("你身上沒有這個孩子。\n");

    if (me->move(environment(who)))
    {
        message_vision("$N把$n從懷裡放了下來。\n", who, me);
        return 1;
    }
    return 0;
}

int do_get(string arg) {
    object me = this_object(), who = this_player();
    object ob1, ob2;
    string fid, mid;
    mapping bro;
    string *ids;

    if (! arg) return 0;
    if (! this_object()->id(arg)) return 0;

    if (environment(me) != environment(who))
        return notify_fail("這裡沒有這個孩子。\n");

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(who, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    fid = query("parents/father", me);
    mid = query("parents/mother", me);

    ob1 = UPDATE_D->global_find_player(fid);
    ob2 = UPDATE_D->global_find_player(mid);

    if(query("id", who) == fid
        || query("id", who) == mid )
    {
        if (query("age") < GETAGE && me->move(who))
        {
            message_vision("$N彎下腰把$n抱了起來，摟在懷裡。\n", who, me);
        }
        else
        {
            message_vision("$N彎下腰一抱卻沒把$n抱起來，小傢伙好沉哪！\n", who, me);
        }
    } else
    if(mapp(bro = query("brothers", ob1)) && sizeof(bro)>0 )
    {
        ids = keys(bro);
        if(member_array(who->query("id", who), ids) != -1 )
        {
            if (query("age") < GETAGE && me->move(who))
            {
                message_vision("$N彎下腰把$n抱了起來，摟在懷裡。\n", who, me);
            }
            else
            {
                message_vision("$N彎下腰一抱卻沒把$n抱起來，小傢伙好沉哪！\n", who, me);
            }
        }
    } else
    if(mapp(bro = query("brothers", ob2)) && sizeof(bro)>0 )
    {
        ids = keys(bro);

        if (member_array(query("id", who), ids) != -1)
        {
            if (query("age") < GETAGE && me->move(who))
            {
                message_vision("$N彎下腰把$n抱了起來，摟在懷裡。\n", who, me);
            }
            else
            {
                message_vision("$N彎下腰一抱卻沒把$n抱起來，小傢伙好沉哪！\n", who, me);
            }
        }
    }
    else
    {
        message_vision("$N蹲下身朝$n伸開雙手，$n卻一下子閃開了．．．\n", who, me);
    }

    UPDATE_D->global_destruct_player(ob1, 1);
    UPDATE_D->global_destruct_player(ob2, 1);

    return 1;
}

int do_kill(string arg) {
    object me, who;
    string verb, what;

    if (! arg) return 0;

    verb = query_verb();
    me = this_player();

    if (verb == "steal")
    {
        if (sscanf(arg, "%s from %s", what, arg) != 2)
            return 0;
    }

    if (!this_object()->id(arg)) return 0;

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(me, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return -1;
    }

    who = this_object();
    if (1)
    {
        switch(verb)
        {
        case "kill":
            // command("chat* " +
            tell_object(environment(this_object()),
            query("name", who) + "拼命地哭了起來：爹～～，娘～～，"+
            query("name", me) + "要殺我．．．快回來呀！\n");
            break;
        case "hit":
            //  command("chat* " +
            tell_object(environment(this_object()),
            query("name", who) + "大哭了起來：爹～～，娘～～，"+
            query("name", me) + "欺負我．．．快回來呀！\n");
            break;
        case "fight":
            // command("chat* " +
            tell_object(environment(this_object()),
            query("name", who) + "哭了起來：爹～～，娘～～，"+
            query("name", me) + "要搶我的糖吃．．．快回來呀！\n");
            break;
        case "steal":
            // command("chat* " +
            tell_object(environment(this_object()),
            query("name", who) + "哭了起來：爹～～，娘～～，"+
            query("name", me) + "要偷吃我的糖！\n");
            break;
        case "beg":
            // command("chat* " +
            tell_object(environment(this_object()),
            query("name", who) + "小嘴一歪哭了起來：爹～～，娘～～，"+
            query("name", me) + "要騙我的糖吃！\n");
            break;
        }
    }
    command(verb);
    return 0;
}

void relay_emote(object ob, string verb) {
    if (! userp(ob)) return;

    switch(verb)
    {
    case "kick":
    case "papaya":
        command("kick "+query("id", ob));
        break;
    case "slap":
    case "slap4":
    case "hammer":
    case "chao":
    case "pig":
        command("slap "+query("id", ob));
        break;
    case "hit":
    case "trip":
    case "drops":
        command("pan "+query("id", ob));
        break;
    case "bite":
        command("bite2 "+query("id", ob));
        break;
    }
}

void relay_whisper(object me, string msg) {
    if(query("id", me) != query("parents/father" )
        && query("id", me) != query("parents/mother") )
    {
        message_vision(query("name", this_object()) + "疑惑地看著$N。\n", me);
        return;
    }

    /*
     * // note, do not allow the order contain "chat", "tell"...
     * // may need disable more later...
     * if (strsrch(msg, "chat") != -1 ||
     * strsrch(msg, "tell") != -1 ||
     * strsrch(msg, "sos")  != -1 ||
     * strsrch(msg, "recruit") != -1)
     * return;
     */

    if (msg)
    {
        remove_call_out ("relaying");
        call_out ("relaying", random(2), msg);
    }
}

void relaying (string msg) {
    // execute the order.
    if (command(msg))
        return;
    else
    {
        if (query_temp("notify_fail")) {
            command("say " + query_temp("notify_fail") + "\n");
            delete_temp("notify_fail");
        }
        else
            command("say 好象不行呀。。。\n");
    }
    return;
}

mixed ask_father() {
    object me, ob;
    string id, name;

    me = this_object();

    id = query("parents/father", me);
    ob = UPDATE_D->global_find_player(id);

    if (! objectp(ob))
        return notify_fail(me->name() + "露出痛苦的表情道：“家父已經去世了，你問家父有何貴幹？！”\n");

    name = query("name", ob);
    command("say 我的父親是個頂天立地的大英雄，" + name + "(" + id + ")就是他的尊號，你聽說過他嗎？");
    UPDATE_D->global_destruct_player(ob, 1);
    return 1;
}

mixed ask_mother() {
    object me, ob;
    string id, name;

    me = this_object();

    id = query("parents/mother", me);
    ob = UPDATE_D->global_find_player(id);

    if (! objectp(ob))
        return notify_fail(me->name() + "露出痛苦的表情道：“家母已經去世了，你問家母有何貴幹？！”\n");

    name = query("name", ob);
    command("say 我的母親是武林第一美女，" + name + "(" + id + ")就是他的尊號，你聽說過她嗎？");
    UPDATE_D->global_destruct_player(ob, 1);
    return 1;
}

int accept_ask(object who, string topic) {
    object ob, ob1, ob2, me = this_object();
    string fid, mid, name, fname, mname;
    mapping bro;
    string *ids;
    string id;

    fid = query("parents/father", me);
    mid = query("parents/mother", me);

    ob1 = UPDATE_D->global_find_player(fid);
    fname = query("name", ob1);

    if(mapp(bro = query("brothers", ob1)) && sizeof(bro)>0 )
    {
        ids = keys(bro);

        foreach (id in ids)
        {
            ob = UPDATE_D->global_find_player(id);
            name = query("name", ob);
            if (topic == id || topic == name)
            {
                if(query("gender", ob) == "男性" )
                {
                    if (query("mud_age", ob) > query("mud_age", ob1))
                        command("say 那是家父的結義兄長，也就是我的伯父。");
                    else
                        command("say 那是家父的義弟，也就是我的叔叔。");

                } else
                {
                    if (query("mud_age", ob) > query("mud_age", ob1))
                        command("say 那是家父的義姐，也就是我的大姑。");
                    else
                        command("say 那是家父的結義妹子，也就是我的小姑。");
                }
                UPDATE_D->global_destruct_player(ob, 1);
                UPDATE_D->global_destruct_player(ob1, 1);
                return 1;
            }
            UPDATE_D->global_destruct_player(ob, 1);
        }
    }

    UPDATE_D->global_destruct_player(ob1, 1);

    ob2 = UPDATE_D->global_find_player(mid);
    mname = query("name", ob2);

    if(mapp(bro = query("brothers", ob2)) && sizeof(bro)>0 )
    {
        ids = keys(bro);

        foreach (id in ids)
        {
            ob = UPDATE_D->global_find_player(id);
            name = query("name", ob);
            if (topic == id || topic == name)
            {
                if(query("gender", ob) == "男性" )
                {
                    if (query("mud_age", ob) > query("mud_age", ob1))
                        command("say 那是家母的結義兄長，也就是我的大舅。");
                    else
                        command("say 那是家母的義弟，也就是我的小舅。");

                } else
                {
                    if (query("mud_age", ob) > query("mud_age", ob1))
                        command("say 那是家母的義姐，也就是我的大姨。");
                    else
                        command("say 那是家母的結義妹子，也就是我的小姨。");
                }
                UPDATE_D->global_destruct_player(ob, 1);
                UPDATE_D->global_destruct_player(ob2, 1);
                return 1;
            }
            UPDATE_D->global_destruct_player(ob, 1);
        }
    }

    UPDATE_D->global_destruct_player(ob2, 1);

    if (topic == fid || topic == fname)
    {
        if(query("id", who) == query("parents/father", me) ||
            query("id", who) == query("parents/mother", me) )
            command("say 那是父親大人的名諱啊，孩兒怎敢忘！");
        else
            command("say 那是家父的名諱，你認識家父嗎？");
        return 1;
    }

    if (topic == mid || topic == mname)
    {
        if(query("id", who) == query("parents/father", me) ||
            query("id", who) == query("parents/mother", me) )
            command("say 那是母親大人的名諱啊，孩兒怎敢忘！");
        else
            command("say 那是家母的名諱，你認識家母嗎？");
        return 1;
    }

    switch (topic)
    {
    case "叫爹爹" :
    case "叫爸爸" :
        if(query("id", who) == query("parents/father", me) )
            command("say 父親大人好！");
        else
            command("say 想佔我便宜，門都沒有！");
        return 1;

    case "叫母親" :
    case "叫媽媽" :
        if(query("id", who) == query("parents/mother", me) )
        {
            command("say 母親大人吉祥！");
            command("cat"+query("id", who));
        }
        else
            command("say 想佔我便宜，門都沒有！");
        return 1;

    case "叫叔叔" :
        if(query("gender", who) != "男性" )
            command("say 你不是男人，我怎麼能叫你叔叔呢？");
        else
            command("say 叔叔好！");
        return 1;
    case "叫阿姨" :
        if(query("gender", who) != "女性" )
            command("say 你不是女人，我怎麼能叫你阿姨呢？");
        else
            command("say 阿姨吉祥！");
        return 1;
    case "叫姑姑" :
        if(query("gender", who) != "女性" )
            command("say 你不是女人，我怎麼能叫你姑姑呢？");
        else
            command("say 姑姑吉祥！");
        return 1;
    default:
        return 0;
    }
}

int is_home(string where) {
    object room;
    mixed pob = get_pob();

    if (strsrch(where, "/dongtian/") != -1) {
        if (pob && (query_temp("youli/report_time/dongtianexit") < time()) ) {
            tell_object(pob, NOR + HIG + query("name") + HIG + "告訴你：我在" + HIC + query("short", environment()) + HIG + "發現了洞天的入口。\n" + NOR);
            set_temp("youli/report_time/dongtianexit", time() + 900);
        }
        return 0;
    }
    if (strsrch(where, query("youli/area_path")) == -1)
        return 0;

    room = get_object(where);
    if (!room || !objectp(room) ||
        room->is_build_room() || room->is_private_room() || room->is_chat_room() ||
        query("no_fight", room) || query("no_kill", room) )
    return 0;

    set_temp("youli/ylrooms/" + replace_string(where, "/", "_"), time());
    return 1;
}


int random_move() {
    mapping exits;
    string *dirs, direction, to_go_place;
    object env;
    if(!mapp(exits = query("exits", environment())))return 0;
    dirs = keys (exits);
    direction = dirs[random(sizeof(dirs))];
    env = environment(this_object());
    to_go_place = query("exits/"+direction, env);
    if (!is_home(to_go_place)) return 0;
    //DEBUG_CHANNEL(command("go " + direction));
    command("go " + direction);
    return 1;
}

int do_killenemy() {
    object me = this_object();
    object room = environment(me);
    object ene = new(__DIR__"baby_enemy");

    if (!room || !room->is_room()) return 0;
    if (ene && ene->move(room)) {
        ene->command("heihei " + query("id", me));
        command("fear");
        ene->kill_ob(me);
        me->kill_ob(ene);
    }
    return 1;
}

int filter_babys(object me) {
    if (!me->is_baby()) return 0;
    return 1;
}

int do_rob(object me) {
    object bag, room, baby, *babys = ({});
    int pow1, pow2;
    mixed pob = get_pob();

    room = environment();
    if (!objectp(room) || !room->is_room())
        return 0;
    babys = filter_array(all_inventory(room), (: filter_babys :));
    if (!babys || !arrayp(babys) || !sizeof(babys))
        return 0;
    baby = babys[random(sizeof(babys))];
    if (!query_temp("dis_all_cmd/time", baby) || query_temp("dis_all_cmd/act", baby)!="youli" )
        return 0;
    bag = query_temp("handing", baby);
    if (!bag || !objectp(bag))
        return 0;
    pow1 = query("combat_exp") +
        3* query("qi") +
        2* query("jing") +
        me->query_str() * 1000000 +
        me->query_con() * 1000000 +
        me->query_dex() * 1000000 +
        me->query_int() * 500000;
    pow1 = pow1 + random(pow1 / 10);
    pow2 = query("combat_exp", baby) +
        3* query("qi", baby) +
        2* query("jing", baby) +
        baby->query_str() * 1000000 +
        baby->query_con() * 1000000 +
        baby->query_dex() * 1000000 +
        baby->query_int() * 500000 +
        baby->query_kar() * 800000;
    pow2 = pow2 * 6 / 5 + random(pow2 / 4);
    if (pow1 < pow2) {
        command("look " + query("id", baby));
        command("consider 罷了，有風險");
        return 0;
    }

    command("heihei " + query("id", baby));
    message_vision(NOR + CYN + "$N" + NOR + CYN + "縱身撲倒$n" + NOR + CYN + "，肆意蹂躪了一番，然後拿著$n" + NOR + CYN + "的包包得意地走了。\n" + NOR, me, baby);
    baby->command("chat* cry " + query("id", baby));
    set_temp("dis_all_cmd/act", "youli_rob", baby);
    set_temp("dis_all_cmd/enemyname", query("name"), baby);
    set_temp("dis_all_cmd/time", 1, baby);
    baby->command("chat* wuwu " + query("id"));

    command("ya");
    if (pob) {
        message_vision(NOR + CYN + "$N" + NOR + CYN + "扯著嗓子大喊了聲：“順豐——”，小哥騎著馬跑來，接過麻布袋“駕、駕……”轉眼就沒影了。\n" + NOR, me);
        message_vision(NOR + YEL + "煙塵滾滾中，快遞小哥騎著一匹小馬駒跑到$N" + NOR + YEL + (random(2) ? "面前" : "身後") +
            "。\n" + NOR + CYN + "快遞小哥大喊了一聲：“戰利品——”，把麻布袋往$N" + NOR + CYN + "懷裡一丟就跑了。\n" + NOR, pob);
        bag->move(pob);
    }
    return 1;
}

mixed get_pob() {
    object pob = query_temp("dis_all_cmd/officer");
    if (!pob || !playerp(pob) || !environment(pob) || !objectp(environment(pob))) {
        return 0;
    }
    return pob;
}

int give_bag() {
    object me = this_object();
    object bag = query_temp("handing");
    mixed pob = get_pob();

    if (undefinedp(bag) || !bag || !objectp(bag) || environment(bag)!= me) {
        return 0;
    }
    command("hand none");
    if (!pob) {
        return 0;
    }
    command("say 此行頗有收穫，叫快遞送給父母作禮物好了。");
    message_vision(NOR + CYN + "$N" + NOR + CYN + "扯著嗓子大喊了聲：“順豐——”，小哥騎著馬跑來，接過麻布袋“駕、駕……”轉眼就沒影了。\n" + NOR, me);
    message_vision(NOR + YEL + "煙塵滾滾中，快遞小哥騎著一匹小馬駒跑到$N" + NOR + YEL + (random(2) ? "面前" : "身後") +
        "。\n" + NOR + CYN + "快遞小哥大喊了一聲：“收包裹——”，把麻布袋往$N" + NOR + CYN + "懷裡一丟就跑了。\n" + NOR, pob);
    bag->move(pob);
    return 1;
}

int get_reward1() {
    object rob, bag, me;
    int kartime;
    mapping ylrooms;
    object where;

    me = this_object();
    where = environment(me);
    if (query("no_fight", where) || query("no_kill", where) || query("sleep_room", where)) return 0;
    if (!random(50) ) { //搶劫別的寶寶幾率
        //if (do_rob(me)) return 0;
        do_rob(me);
        return 0;
    }
    if (query_temp("youli/encounter/last_time") > time()) return 0;
    ylrooms = query_temp("youli/ylrooms");
    if (random(100)<3 && !undefinedp(ylrooms) && mapp(ylrooms) && sizeof(ylrooms)>7 )   //走路超過8個房間，才能開始獲得獎勵
    {
        kartime = me->query_kar();
        kartime = 100 - kartime;
        if (kartime < 10) kartime = 10;
        set_temp("youli/encounter/last_time", time() + 80 + random(kartime));
        kartime = me->query_kar();
        kartime /= 30;
        if (kartime > 3) kartime = 3;
        if (!random(9 - kartime)) {
            if (query("youli/dongtian_dir")) {
                //DEBUG_CHANNEL("youli...洞天令" + ctime(time()));
                if (BABYDTC->convert_ling(query("youli/dongtian_dir"), random(20), me) ) {
                    rob = present("dongtian ling", me);
                    CHANNEL_D->channel_broadcast("dt", NOR + HIW + "據說" + query("name") + NOR + HIW + "在遊歷過程中發現了一塊" + query("name", rob) + NOR + HIW + "。\n" + NOR);
                    message_vision(NOR + CYN + "$N" + NOR + CYN + (random(2) ? "東扒西拉" : "東張西望") + "地，在" + (random(2) ? "路邊" : "地上") + (random(2) ? "拾到" : "撿起") + "一塊$n" + NOR + CYN + "，大喜若狂" + NOR + CYN + "...\n" + NOR, me, rob);
                    remove_call_out("do_killenemy");
                    call_out("do_killenemy", 1);
                }
            } else { //不能獲得洞天令的區域則獲得萬象天書，必須opened，避免留下複製後的..
                rob = new("/d/dongtian/obj/wanxiangbook");
                set("no_open_msg", 1, rob);
                if (rob->move(me)) {
                    if (rob->do_open(query("id", rob))<100) {
                        //DEBUG_CHANNEL("youli...萬象天書：" + query("name",rob));
                        CHANNEL_D->channel_broadcast("dt", NOR + HIW + "據說" + query("name") + NOR + HIW + "在遊歷過程中發現了一本" + query("name", rob) + NOR + HIW + "。\n" + NOR);
                    }
                    message_vision(NOR + CYN + "$N" + NOR + CYN + (random(2) ? "東扒西拉" : "東張西望") + "地，在" + (random(2) ? "路邊" : "地上") + (random(2) ? "拾到" : "撿起") + "一本$n" + NOR + CYN + "，大喜若狂" + NOR + CYN + "...\n" + NOR, me, rob);
                    remove_call_out("do_killenemy");
                    call_out("do_killenemy", 1);
                }
            }
        } else {
            /*
             * rndyl = sizeof(ylrooms);
             * if (rndyl > 15) rndyl = 15;
             * if (rndyl > random(45)) {
             * //DEBUG_CHANNEL("youli...寶箱2" + ctime(time()));
             * rob = new("/adm/npc/obj/xianghy2");
             * } else {
             * //DEBUG_CHANNEL("youli...寶箱" + ctime(time()));
             * rob = new("/adm/npc/obj/xianghy");
             * }
             * delete("no_put", rob);
             * delete("no_get", rob);*/
            rob = new("/adm/npc/obj/xianghy3");
            message_vision(NOR + CYN + "$N" + NOR + CYN + (random(2) ? "東扒西拉" : "東張西望") + "地，在" + (random(2) ? "路邊" : "地上") + (random(2) ? "拾到" : "撿起") + "$n" + NOR + CYN + "。\n" + NOR, me, rob);
            rob->move(me);
        }

        bag = query_temp("handing", me);
        if (undefinedp(bag) || !bag || !objectp(bag) || environment(bag)!= me) {
            bag = new("/d/city/npc/obj/mabudai");
            set("no_steal", "小孩的東西你也偷？不如直接動手搶吧。\n", bag);
            bag->move(me);
            me->command("hand " + query("id", bag));
        }
        me->command("put " + query("id", rob) + " in " + query("id", bag));
        if (query_temp("youli/encounter/bag_item_n") > 44 + random(5)) {
            give_bag();
            delete_temp("youli/encounter/bag_item_n");
        } else {
            addn_temp("youli/encounter/bag_item_n", 1);
        }
        me->start_busy(3);
        return 1;
    }

    return 0;
}


void consider() {
    string *basic = ({ "force", "dodge", "unarmed", "cuff", "strike", "finger",
        "hand", "claw", "sword", "blade", "staff", "hammer",
        "club", "whip", "dagger", "throwing", "parry", "magic",
        "medical", "poison", "chuixiao-jifa", "tanqin-jifa",
        "guzheng-jifa", "cooking"
    });
    string act;
    string *chat_chance_combat_here = ({ (: exert_function, "powerup": ) }), *my_skill,
        *basic_skill = ({}), *use_skill = ({}), dir;
    mapping skills;
    int i, j, k;
    mixed *file;
    object me = this_object();
    mixed pob = get_pob();

    if (! environment())
        return;

    if (query_temp("dis_all_cmd/time")) {
        act = query_temp("dis_all_cmd/act");
        if (query_temp("dis_all_cmd/time") > time()) {
            if (act) {
                if (act == "youli" && !me->is_fighting() && !me->is_busy()) {
                    if (!get_reward1()) random_move();
                }
            }
        } else {
            if (act) {
                if (act == "youli") {
                    give_bag();
                    if (pob) tell_object(pob, NOR + HIG + query("name") + HIG + "告訴你："+query_temp("dis_all_cmd/cact") + "回來啦，玩得很高興，我先回學堂讀書去了。\n" + NOR);
                    command("say 終於可以回家啦！");
                    command("spank " + query("id", this_object()));
                    message_vision(NOR + YEL + "$N" + NOR + YEL + "一溜煙地跑了。\n" + NOR, this_object());
                    this_object()->move(BABYSCH);
                } else if (act == "youli_rob") {
                    if (pob) tell_object(pob, NOR + HIG + query("name") + HIG + "告訴你：倒黴，我被"+query_temp("dis_all_cmd/enemyname") + "打了一頓。現在很難過，先回學堂玩去了。\n" + NOR);
                    command("inn 偶被欺負了");
                    message_vision(NOR + YEL + "$N" + NOR + YEL + "一溜煙地跑了。\n" + NOR, this_object());
                    this_object()->move(BABYSCH);
                }
                delete(act);
                delete_temp(act);
                delete("dis_all_cmd");
                delete_temp("dis_all_cmd");
                set("chat_chance", query("chat_chance_bak"));
                save();
                this_object()->reset_action();
            }
        }
        return;
    }

    skills = me->query_skills();
    if (sizeof(skills) && sizeof(skills) > query("skills_learned"))
    {
        my_skill = keys(skills);
        for (i = 0; i < sizeof(basic); i++)
            if (member_array(basic[i], my_skill) != -1)
            basic_skill += ({ basic[i] });

        for (i = 0; i < sizeof(my_skill); i++)
            if (SKILL_D(my_skill[i])->type() != "knowledge"
            &&  member_array(my_skill[i], basic) == -1)
            use_skill += ({ my_skill[i] });

        for (i = 0; i < sizeof(basic_skill); i++)
            for (j = 0; j < sizeof(use_skill); j++)
            if (SKILL_D(use_skill[j])->valid_enable(basic_skill[i])
            &&  ! stringp(query_skill_mapped(basic_skill[i])))
        {
            map_skill(basic_skill[i], use_skill[j]);
            if (sizeof(me->query_skill_prepare()) < 2)
                if (basic_skill[i] == "finger"
                ||  basic_skill[i] == "strike"
                ||  basic_skill[i] == "hand"
                ||  basic_skill[i] == "cuff"
                ||  basic_skill[i] == "claw"
                ||  basic_skill[i] == "unarmed")
            prepare_skill(basic_skill[i], use_skill[j]);

        } else
        continue;

        if (sizeof(skills) > query("skills_learned"))
            set("perform_skills", 0);

        if (! query("perform_skills"));
        {
            for (i = 0; i < sizeof(basic_skill); i++)
                if (basic_skill[i] != "magic" && basic_skill[i] != "medical"
                &&  basic_skill[i] != "cooking"
                &&  stringp(query_skill_mapped(basic_skill[i])))
            {
                dir = "/kungfu/skill/" + query_skill_mapped(basic_skill[i]) + "/";
                if (SKILL_D(query_skill_mapped(basic_skill[i]))->valid_enable("force"))
                    dir += "perform/";
                if (file_size(dir) != -2)
                    continue;
                file = get_dir(dir, -1);
                if (! sizeof(file))
                    continue;

                for (k = 0; k < sizeof(file); k++)
                {
                    if (file[k][0][strlen(file[k][0]) - 2..strlen(file[k][0])] != ".c")
                        continue;
                    file[k][0] = replace_string(file[k][0], ".c", "");
                    chat_chance_combat_here +=
                    ({ (: perform_action, basic_skill[i] + "." + file[k][0]: ) });
                }
            } else
            continue;

            set("chat_msg_combat", chat_chance_combat_here);
            set("perform_skills", 1);
        }

        set("chat_msg_combat", chat_chance_combat_here);
        reset_action();
        set("skills_learned", sizeof(skills));
        //command("say 嘻嘻，我知道了，我會用了！\n");
    }

    set("jiali", query_skill("force") / 2 + 10);
    save();

    //command("say 嘻嘻，都記住了，可以了！\n");
    return;
}

int accept_object(object who, object ob) {

    if (query_temp("dis_all_cmd/time") > time()) {
        tell_object(who, NOR + "孩子正在"+query_temp("dis_all_cmd/cact") + "中，你無法打斷他。\n" + NOR);
        return 0;
    }

    if(query("id", who) == query("parents/father" )
        || query("id", who) == query("parents/mother") )
    {
        remove_call_out("provide");
        call_out("provide", 1);
        return 1;
    } else
    return 0;
}

void provide() {
    object *ilist, ob;
    object weapon, armor;
    int i;

    if (query_temp("dis_all_cmd/time") > time()) return;
    if (! environment()) return;
    ilist = all_inventory(this_object());
    if (sizeof(ilist) < 1) return;

    for (i = 0; i < sizeof(ilist); i++)
    {
        ob = ilist[i];
        if(query("weapon_prop/damage", ob) )
        {
            if (objectp(weapon = query_temp("weapon")) && weapon != ob
                && query("weapon_prop/damage", ob)>
                query("weapon_prop/damage", weapon) )
            weapon->unequip();
            command("wield "+query("id", ob));
        }

        if(query("armor_prop/armor", ob) )
        {
            if (objectp(armor = query_temp("armor/" + query("armor_type", ob)))
                &&  armor != ob
                && query("armor_prop/armor", ob)>
                query("armor_prop/armor", armor) )
            armor->unequip();
            command("wear "+query("id", ob));
        }

        if(query("food_remaining", ob) )
            command("eat "+query("id", ob));
        else
            if(query("liquid/remaining", ob) )
            command("drink "+query("id", ob));
    }

    set("jiali", query_skill("force") / 2 + 10);

    //command("sweat");
    return;
}

void heart_beat() {
    string act = query_temp("dis_all_cmd/act");

    if (query_temp("save_time") < time() && environment()) {
        save();
        set_temp("save_time", time() + 600);
    }

    if (!random(4) && act) {
        if (act == "youli" && !is_fighting() && !is_busy()) {
            delete_temp("no_perform");
            delete_temp("no_exert");
            set("eff_qi", query("max_qi"));
            set("qi", query("max_qi"));
            set("eff_jing", query("max_jing"));
            set("jing", query("max_jing"));
        }
    }

    return ::heart_beat();
}
