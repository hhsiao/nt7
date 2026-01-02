#include <ansi.h>
inherit NPC;
#define QUESTJINSHE "skybook/bixue/"

void create() {
    set_name("溫方義", ({ "wen fangyi", "wen", "fangyi" }));
    set("gender", "男性");
    set("title", "溫家五老");
    set("long",
        "他就是溫家五老的老二溫方義。\n"
        "一個五十來歲的老者，一雙眼睛透出精光。\n");
    set("str", 25);
    set("dex", 25);
    set("con", 25);
    set("int", 25);
    set("per", 25);
    set("shen_type", -1);
    set("unique", 1);

    set_skill("force", 300);
    set_skill("dodge", 300);
    set_skill("parry", 300);
    set_skill("blade", 300);
    set_skill("cuff", 300);
    set_skill("yijin-jing", 300);
    set_skill("shaolin-shenfa", 300);
    set_skill("wenjia-daofa", 300);
    set_skill("wenjia-quan", 300);
    set_skill("wuxing-zhen", 200);

    map_skill("force", "yijin-jing");
    map_skill("cuff", "wenjia-quan");
    map_skill("blade", "wenjia-daofa");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("parry", "wenjia-quan");

    prepare_skill("cuff", "wenjia-quan");


    set("combat_exp", 2000000);
    set("max_qi", 30000);
    set("max_jing", 3000);
    set("max_neili", 5000);
    set("eff_jingli", 3000);
    set("qi", 30000);
    set("jing", 3000);
    set("jingli", 3000);
    set("neili", 5000);

    setup();

    carry_object(ARMOR_D("cloth"))->wear();
    carry_object("/clone/weapon/blade")->wield();

}
void init() {
    object me, ob;

    ::init();

    ob = this_object();
    me = this_player();

    if(interactive(me) && visible(me) &&
        !is_fighting()) {
            NPC_D->copy_from_me(ob, me, 70, 1);
            kill_ob(me);
    }
    remove_call_out("dest");
    call_out("dest", 600, ob);

}

void zhen(object ob) {
    if(!ob ) return;
    command("zhen in");
    call_out("zhen", 1, ob);
}
void kill_ob(object me) {
    object ob = this_object();
    if(!me ) return 0;
    call_out("zhen", 0, ob);
    remove_call_out("checking");
    call_out("checking", 1, me, ob);
    return ::kill_ob(me);
}

//檢查，quest過程不允許死亡
int checking(object me, object ob) {
    remove_call_out("checking");
    call_out("checking", 1, me, ob);

    if(!living(me) && living(ob) && query("jing", ob)>0 && query("qi", ob) > 0 ) {
        remove_call_out("checking");
        tell_room(environment(me), HIB"\n"+me->name() + "眼看就是不敵，突然一股勁風襲來，五行陣一頓出現一道間隙，"+me->name() + "順勢闖出溫家堡莊。\n"NOR);
        me->move("/d/shiliang/gate");
        tell_room(environment(me), HIB"\n一個身影突然飛來，待你仔細看來，原來是"+me->name() + "，只見"+me->name() + "突然一頓，竟然昏倒在地。\n"NOR);
        delete_temp(QUESTJINSHE + "start_kill", me);
        delete_temp(QUESTJINSHE + "kill", me);
        delete_temp(QUESTJINSHE + "kill_5wen", me);
        delete_temp(QUESTJINSHE + "have_kill", me);
        set("qi", 100, me);
        set("jing", 100, me);
        //log_file("quest/JINSHE",sprintf("%s紀錄：%s(%s)金蛇劍法失敗。經驗%d。\n",ob->name(1),me->name(1),query("id", me),query("combat_exp", me)));
        tell_room(environment(ob), ob->name() + "哼了一聲：“快追！”\n");
        destruct(ob);
        return 1;
    }
    if(!me || me->is_ghost() || query("eff_qi", me)<query("max_qi", me) / 15 || query("qi", me)<query("max_qi", me) / 20 || environment(me) != environment(ob)){
        remove_call_out("checking");
        remove_call_out("do_lost");
        call_out("do_lost", 0);
        return 1;
    }
}

void do_lost() {
    object me, ob;
    ob = this_object();
    if(!ob) return;
    me = present(query("kill_id", ob), environment(ob));
    if(!me)me = find_player(query("kill_id", ob));
    if(me)
    {
        delete(QUESTJINSHE + "start_kill", me);

        delete_temp(QUESTJINSHE + "kill", me);
        delete_temp(QUESTJINSHE + "have_kill", me);
        delete_temp(QUESTJINSHE + "kill_5wen", me);

        //log_file("quest/JINSHE",sprintf("%s紀錄：%s(%s)金蛇劍法失敗。經驗%d。\n",ob->name(1),me->name(1),query("id", me),query("combat_exp", me)));
    }
    tell_room(environment(ob), ob->name() + "哼了一聲：“就這點本事啊！”\n");
    destruct(ob);
}

void dest(object ob) {
    if(!ob) return;
    tell_room(environment(ob), HIR + "\n"+ob->name() + "哼了一聲，點子厲害，我們撤~~~~~~~\n"NOR);
    destruct(ob);
}

varargs void die(object killer)
{
    object ob = this_object();

    if(!killer ) killer = ob->query_last_damage_from();
    if(killer )
    {
        if(query_temp(QUESTJINSHE + "start_kill", killer) )
        {
            if(!query_temp(QUESTJINSHE + "kill", killer) )
            {
                addn_temp(QUESTJINSHE + "kill_5wen", 1, killer);
                if(query_temp(QUESTJINSHE + "kill_5wen", killer) == 5 )
                {
                    set(QUESTJINSHE + "over", 1, killer);
                    set_temp(QUESTJINSHE + "have_kill", 1, killer);
                    delete_temp(QUESTJINSHE + "kill_5wen", killer);
                }
            }
        }
    }

    ::die();
}
