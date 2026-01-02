// This program is a part of NT MudLIB

#include <ansi.h>;
inherit NPC;

#define QUESTDIR  "skybook/連城訣/"
#define QUESTDIR1 "skybook/連城訣/復仇篇/"
#define QUESTDIR2 "skybook/連城訣/解救丁典篇/"
#define QUESTDIR3 "skybook/連城訣/雪谷激鬥篇/"
#define QUESTDIR4 "skybook/連城訣/寶藏篇/"
#define QUESTDIR5 "skybook/連城訣/武功/"

string ask_me();
string ask_me2();
string ask_book();
string ask_book2();
void do_kill(object ob);

void create () {
    object weapon;
    set_name("狄雲", ({"di yun", "di"}));
    set("long", "他長臉黝黑，顴骨微高，粗手大腳，象是湘西鄉下常見的莊稼漢子。\n");
    set("gender", "男性");
    set("age", 24);
    set("combat_exp", 20000000);
    set("max_qi", 20000);
    set("max_jing", 20000);
    set("max_neili", 30000);
    set("qi", 20000);
    set("jing", 20000);
    set("neili", 30000);
    set("str", 125);
    set("int", 125);
    set("con", 125);
    set("dex", 125);
    set("per", 26);

    set_skill("force", 320);
    set_skill("dodge", 320);
    set_skill("sword", 220);
    set_skill("parry", 320);
    set_skill("yanfly", 200);
    set_skill("liancheng-jianfa", 320);
    set_skill("shenzhaojing", 300);
    set_skill("xuedao-daofa", 200);

    map_skill("sword", "liancheng-jianfa");
    map_skill("force", "shenzhaojing");
    map_skill("blade", "xuedao-daofa");
    map_skill("parry", "xuedao-daofa");
    map_skill("unarmed", "shenzhaojing");
    map_skill("dodge", "yanfly");

    set("chat_chance_combat", 90);
    set("chat_msg_combat", ({
        (: perform_action, "sword.cijian" :),
        (: perform_action, "sword.erguang" :),
        (: perform_action, "sword.qujian" :),
        (: perform_action, "blade.huan" :),
        (: perform_action, "blade.ying" :),
        (: perform_action, "blade.shi" :),
        (: perform_action, "blade.xue" :),

    }) );

    set("inquiry", ([
        "水笙" : (: ask_me :),
        "劍譜":     (: ask_book :),
        "丁典":     (: ask_book2 :),
        "神照經":     (: ask_book2 :),
        "萬震山":     "萬震山這個狗賊我非殺了他不可。\n"
        ]));

    set_temp("apply/attack", 120);
    set_temp("apply/defense", 120);
    set_temp("apply/armor", 120);
    set_temp("apply/damage", 520);


    set("wucan_count", 1);
    set("baodao_count", 1);
    set("book_count", 1);

    setup();
    carry_object("/clone/cloth/cloth")->wear();
    if (clonep())
    {
        weapon = new(WEAPON_DIR"treasure/xblade" );
        if (weapon->violate_unique() )
        {
            destruct(weapon );
            weapon = new("/clone/weapon/gangdao" );
        }
        weapon->move(this_object());
        weapon->wield();
    }
}

string ask_me() {

    if (query("wucan_count") < 1)
        return "水笙姑娘？她在雪域等著我？";

    addn("wucan_count", -1);
    set_temp("marks/wucan", 1, this_player());
    return "水笙姑娘？她在雪域等著我？她有什麼東西捎給我麼？";
}

int accept_object(object who, object ob) {
    object obj;

    if((string)query("id", ob) == "wan zhenshan" )
    {
        write(HIC "\n狄雲說道：這位" + RANK_D->query_respect(who) + "，如此大恩大德，在下實不知何以為報。\n");
        write(HIC "\n狄雲大喜道：狗賊！想不到你也有今天！！。\n"NOR);
        call_out("destroying", 1, this_object(), ob);
        set_temp("marks/lianchenpu", 1, who);
        return 1;
    }

    if(query("id", ob) != "dachang" )
        return notify_fail("給我這東西有什麼用？");

    message_vision("狄雲笑著說道：“謝謝你！這位" + RANK_D->query_respect(ob) + "，辛苦你了。”\n", who);
    if(!query_temp("marks/wucan", who) )
    {
        return 1;
    }
    obj = new(ARMOR_DIR"treasure/wucanyi");
    delete_temp("marks/wucan", this_player());
    if (obj->violate_unique() || uptime() < 300)
    {
        destruct(obj );
        return 1;
    }
    message_vision("狄雲對$N說道：“這件烏蠶衣也不算是什麼寶貝，聊表心意吧！”狄雲從懷裡掏出一團不起眼的東西，遞到$N的手上。\n", who);
    obj->move(this_player());
    return 1;
}

void destroying(object me, object obj) {
    destruct(obj);
    return;
}

void do_kill(object ob) {
    object me;
    me = this_object();

    if (interactive(ob))
    {
        command("say 你這惡賊竟敢打我劍譜的主意，給我納命來！\n");
        me->set_leader(ob);
        remove_call_out("kill_ob");
        call_out("kill_ob", 1, ob);
    }

}

string ask_book() {
    object ob, me;

    me = this_player();
    if(!query_temp("marks/lianchenpu", me) ) return "你說什麼? \n";

    if((int)query("shen", me)<100000 )
        return "劍譜落入宵小之手，難免是萬震山第二。\n";

    if(query("book_count") > 0 )
    {
        write(HIC "狄雲說著轉身從萬震山屍身上搜出一本破舊書本，遞了給你。\n");

        add("book_count", -1);
        ob = new ("/clone/book/lian_book");
        ob->move(this_player());
        command("rumor "+query("name", me) + "拿到連城劍譜啦。\n");
        return "這本連城劍譜被這狗賊霸佔多時了，現在就贈與你吧。\n";
    }
    else return "你來晚了，現在連城劍譜已不在此處。\n";

}

string ask_book2() {
    object me;
    int i;
    me = this_player();

    if(!query(QUESTDIR + "active", me) )
        return "你說什麼? \n";

    if(!query_temp("marks/lianchenpu", me) )
        return "請先幫我把萬震山這惡人抓來吧！ \n";

    if(!query_temp("tssword", me) )
        return "你幫我找到唐詩劍譜了嗎? \n";

    if(((int)query("combat_exp", me)<=1000000) )
    {
        message_vision("$N對$n說道： 你的武功太差了，等武功好點再來吧！\n", this_object(), me);
        return " 快去吧。\n";
    }

    if(((int)query(QUESTDIR2 + "/解救丁典", me)>=1 ))
    {
        message_vision("$N對$n說道： 我不是已經讓你去救丁大哥過了嗎? \n", this_object(), me);
        return " 快去吧。\n";
    }

    if((int)query("shen", me)<100000 )
        return "你這惡人，有什麼資格去救丁大哥?\n";

    command("bow " + query("id", me));
    message_vision("$N對$n說道： 多謝幫我手刃仇人。\n", this_object(), me);
    message_vision("$N對$n說道： 我大哥丁典被關在江凌知府中，請幫我去看看他吧。\n", this_object(), me);

    set(QUESTDIR2 + "/解救丁典", 1, me);
    SKYBOOK_D->check_skybook(me, "連城訣");

    i = 200 + random(800);

    me->add("combat_exp", i + 9880);
    me->add("potential", i*12);

    tell_object (me, "你贏得了"+chinese_number(i + 9880) + "點經驗"+
        chinese_number(i*12) + "點潛能！\n");

}
