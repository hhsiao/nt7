#include <ansi.h>
inherit NPC;

#define gold_limit  100000
#define time_limit  900
#define level_limit 800

private void add_all_inquiry();
private void greeting(object me);
private int ask_test(object me, object ob);
private int ask_money(object me, object ob);
private int ask_faction(object me, object ob);
private int ask_all_faction(object me, object ob);
private int setskills(string arg, object me, object ob);

string *all_knowledge = ({
"literate",
"buddhism",
"taoism",
"qimen-wuxing",
"dacheng-fofa",
});

void create()
{
    set_name("榮榮", ({ "rong rong", "rong" }));
    set("nickname", HIG "ask rong about test" NOR);
    set("title", HIY "測試引導員" NOR);
    set("gender", "男性");
    set("shen", 0);
    set("age", 20);
    set("per", 20);
    set("no_get", 1);
    set("wiz_tester", 1);
    set("combat_exp", 10000000);
    set("attitude", "friendly");
    set("long", "這個人看上去永遠是一副沒有睡醒的樣子。\n");

    setup();
    carry_object("/clone/misc/cloth")->wear();
    add_all_inquiry();
}

void init()
{
    add_action("setskills", "setskill");
    if(this_object()->is_livings() && !wizardp(this_player()))
    {
        remove_call_out("greeting");
        call_out("greeting", 1, this_player());
    }
    ::init();
}

private void greeting(object me)
{
    if(!me || environment(me) != environment())
        return;
    tell_object(me, this_object()->name(1) + "向你嘻皮笑臉的道：“這位"
                    + RANK_D->query_respect(me) + "也來參加測試("
                    HIY "ask rong about test" NOR")吧？！”\n");
}

private void add_all_inquiry()
{
    int i;
    string type;
    mapping *all_skill, all_inquiry;

    all_inquiry = ([]);
    all_skill   = FACTION_D->query_all_skill();
    for(i = 0; i < sizeof(all_skill); i++)
    {
        all_inquiry += ([ all_skill[i]["name"] : (: ask_faction :)]);
    }

    all_inquiry += ([

        "test"  : (: ask_test :),
        "money" : (: ask_money :),
        "skill" : (: ask_all_faction :),
    ]);

    this_object()->set("inquiry", all_inquiry);
}

private int ask_test(object me, object ob)
{
    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, ob->name(1) + "乾咳了兩聲，裝腔作勢的說道：\n");
    tell_object(me, HIW@TEXT

請按照下列關鍵字來向測試引導員進行查詢：

    test  ：獲取測試引導員幫助信息
    money ：獲取供測試用的錢莊存款
    skill ：查詢可供選擇的武功技能

    指令格式：ask rong about <關鍵字>


    如果想更換供測試用的技能，請使用setskill指令

    指令格式：setskill <你的ID> use <技能名稱>

    注意：更換技能將先會刪除你身上原有的所有技能

TEXT NOR);
    return 1;
}

private int ask_money(object me, object ob)
{
    me = this_player();
    ob = this_object();

    if(wizardp(me))
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：你不是巫師嗎？"
                                            "自己call就行了。\n" NOR);
        return 1;
    }

    if(time() - me->query("set_skill/money") < time_limit)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：不要太貪心，前後兩次"
                                            "獲取測試用的金錢之間必須間隔"
                                            + chinese_number(time_limit/60) +
                                            "分鐘以上。\n" NOR);
        return 1;
    }

    me->set("set_skill/money", time());
    me->set("bank/gold", gold_limit);
    message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
    tell_object(me, HIC + ob->name(1) + "點頭道：供測試用的金錢"
                    HIY + chinese_number(gold_limit) + "兩黃金"
                    HIC "已經打到你的錢莊帳戶上了。\n" NOR);
    return 1;
}

private int ask_faction(object me, object ob)
{
    string topic;

    me = this_player();
    ob = this_object();

    message("vision", ob->name(1) + "在" + me->name() + "耳邊小聲的"
                      "說了幾句話。\n", environment(me), ({ me, ob }));
    tell_object(me, ob->name(1) + "乾咳了兩聲，裝腔作勢的說道：\n");

    topic = me->query_temp("last_ask/topic");
    if(me->query_temp("ask_all_faction"))
    {
        topic = "";
        FACTION_D->show_skill(me, 0);
    }
    else
    {
        FACTION_D->show_skill(me, topic);
    }

    if(me->query_temp("ask_all_faction"))
        me->delete_temp("ask_all_faction");

    return 1;
}

private int ask_all_faction(object me, object ob)
{
    me = this_player();
    ob = this_object();

    me->set_temp("ask_all_faction", 1);
    ask_faction(me, ob);
    tell_object(me, HIC + ob->name(1) + "悄聲道：可用某項技能的名稱"
                                        "作為關鍵字向我查詢，以獲取"
                                        "進一步的信息。\n" NOR);
    return 1;
}

private int setskills(string arg, object me, object ob)
{
    int i;
    object obj;
    string who, skill;

    me = this_player();
    ob = this_object();

    if(!arg || sscanf(arg, "%s use %s", who, skill) != 2)
        return notify_fail(HIW "指令格式：setskill <你的ID> "
                               "use <技能名稱>\n" NOR);

    obj = present(who, environment(me));
    if(!objectp(obj))
        return notify_fail(YEL + ob->name(1) + "疑惑的道：你要設定"
                                               "誰的技能？\n" NOR);

    if(obj != me)
        return notify_fail(YEL + ob->name(1) + "搖頭道：你只能更換"
                                               "自己的測試用技能。\n" NOR);

    if(wizardp(me))
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：你不是巫師嗎？"
                                            "自己call就行了。\n" NOR);
        return 1;
    }

    if(time() - me->query("set_skill/time") < time_limit)
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "搖頭道：不要太頻繁，前後兩次"
                                            "更換測試用的技能之間必須間隔"
                                            + chinese_number(time_limit/60) +
                                            "分鐘以上。\n" NOR);
        return 1;
    }

    if(me->query("generation_skill/name") == skill)
        return notify_fail(YEL + ob->name(1) + "搖頭道：你當前使用的技能正是「"
                               + skill + "」，無須重複設定。\n" NOR);

    me->set("str", 30);
    me->set("int", 10);
    me->set("con", 60);
    me->set("dex", 30);
    me->set("con_improve_time", 50);
    me->set("food", (int)me->max_food_capacity());
    me->set("water", (int)me->max_water_capacity());

    me->set("set_skill/level", level_limit);
    FACTION_D->gen_npc(me, skill);

    for(i = 0; i < sizeof(all_knowledge); i++)
    {
        me->set_skill(all_knowledge[i], level_limit);
    }

    if(me->query("generation_skill/name") == skill)
    {
        me->set("set_skill/owner", "TEST_D");
        me->set("set_skill/time", time());
        message("vision", ob->name(1) + "點了點頭，在" + me->name() +
                           "耳邊小聲說了幾句話。\n", environment(me),
                                                     ({ me, ob }));
        tell_object(me, HIC + ob->name(1) + "點頭道：你供測試用的技能被設定為『"
                        HIW + skill + HIC "』，等級為"
                        HIY + chinese_number(level_limit) +
                        HIC "級。\n" NOR);
        return 1;
    }
    else
    {
        message("vision", ob->name(1) + "搖了搖頭，在" + me->name() +
                       "耳邊小聲說了幾句話。\n", environment(me),
                                                 ({ me, ob }));
        tell_object(me, YEL + ob->name(1) + "疑惑的道：你是不是搞錯了啊，有『"
                                          + skill + "』這種技能可選嗎？\n" NOR);
        return 1;
    }
}
