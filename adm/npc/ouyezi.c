// Written by Lonely@mud123.com

#include <ansi.h>
inherit NPC;

int ask_qiling();
void create() {
    set_name("歐冶子", ({ "ouye zi", "zi" }) );
    set("nickname", RED "赤心劍膽" NOR );
    set("gender", "男性" );
    set("age", 60);
    set("long",
        "他頭上包著頭巾，三縷長髯飄灑胸前，面目清瘦但紅暈有光，\n"
            "二目炯炯有神，爍爍閃著竟似是凜凜的劍光，渾身似乎都包圍\n"
            "在一股劍氣之中。\n");
    set("str", 25);
    set("dex", 20);
    set("con", 17);
    set("int", 30);
    set("shen_type", 0);
    set("max_neli", 5000);
    set("jiali", 50);
    set_skill("unarmed", 100);
    set_skill("dodge", 100);
    set_skill("jiuyin-baiguzhao", 200);
    set_skill("force", 150);
    set_skill("sword", 150);
    set_skill("bibo-shengong", 100);
    set_skill("luoying-shenjian", 100);
    set_skill("parry", 90);
    set_skill("anying-fuxiang", 100);
    set_temp("apply/attack", 50);
    set_temp("apply/defense", 50);
    set_temp("apply/damage", 50);

    set("combat_exp", 25000000);

    map_skill("force", "bibo-shengong");
    map_skill("parry", "luoying-shenjian");
    map_skill("sword", "luoying-shenjian");
    map_skill("unarmed", "jiuyin-baiguzhao");
    map_skill("dodge", "anying-fuxiang");

    set("attitude", "peaceful");
    create_family("玄天派", 1, "弟子");

    set("inquiry", ([
        "鑄劍" : "我已經很久很久沒有鑄劍了，你還是找我徒弟干將吧。\n",
        "啟靈" : (: ask_qiling() :)
        ]) );
    setup();
    set("chat_chance", 3);
    set("chat_msg", ({
            "歐冶子撫劍而歌：巨闕神兵兮，人鑄就。蓋世寶劍兮，配英雄！\n",
        "歐冶子低頭沉吟，似乎在思考什麼。\n",
        "歐冶子低頭沉思：我深信，每一把武器中都存在著一絲靈智。\n",
        "歐冶子嘆了一口氣：神兵配英雄，可英雄。。。。。。\n"
        }) );
    carry_object("/clone/misc/cloth")->wear();
    carry_object("/clone/weapon/changjian")->wield();
}

void init() {
    add_action("do_qiling", "qiling");
}

int ask_qiling() {
    object me = this_player();
    object ob = this_object();

    message_vision(CYN "$N對$n" CYN "說道：每一把裝備中都存在著一絲靈智，裝備啟靈需要以下物品。\n"
        "       1、銀行存款黃金十萬兩\n"
            "       2、超能力水晶或裝備之魂 1 個\n"
            "       3、無名之物或寰宇天晶 1 個（使用超能力水晶則不需要無名和天晶）\n"
            "       qiling <裝備id> with <裝備之魂>\n" NOR, ob, me);
    return 1;
}

int do_qiling(string arg) {
    mapping data = ([]);
    object me;
    object ob, ob1, ob2;
    string item, what, type;
    int status, qlvl, success;

    me = this_player();

    if(me->is_busy() )
        return notify_fail(BUSY_MESSAGE);

    if(!arg || sscanf(arg, "%s with %s", item, what ) != 2 )
        return notify_fail("給裝備啟靈指令格式：qiling <裝備> with <裝備之魂> \n");

    if(!objectp(ob = present(item, me)) )
        return notify_fail("你身上沒有這樣裝備用來啟靈。\n");

    if(query("equipped", ob) )
        return notify_fail("你先解除" + ob->name() + "的裝備再說！\n");

    if(!ob->is_item_make() )
        return notify_fail("這樣物品不能啟靈品質。\n");

    if(query("qianghua/level", ob) < 7 )
        return notify_fail(ob->name() + "必須達到強化 7 級才能啟靈。\n");
    /*
     * if( ob->item_owner() != query("id", me) )
     * return notify_fail("這個，好象不屬於你吧，這樣不大合適。\n");
     */

    qlvl = query("status", ob);
    if(!qlvl )
    {
        set("status", 1, ob);
        qlvl = 1;
    }
    if(qlvl == 6 )
        return notify_fail(ob->name() + "已經成功產生器魂了，不需要繼續啟靈了。\n");

    // 需要裝備之魂或超能力水晶
    if(!objectp(ob1 = present(what, me)) || (!ob1->is_equip_soul() && !ob1->is_spe_crystal()) )
        return notify_fail("你身上沒有啟靈需要的超能力水晶或裝備之魂吧？\n");

    if(ob1->is_spe_crystal() && query("qiling_level", ob1) <= qlvl )
        return notify_fail("超能力水晶的能力儲備不足以給"+ob->name() + NOR"裝備啟靈！\n");

    if(ob1->is_equip_soul() )
    {
        // 需要無名之物
        if(!objectp(ob2 = present("no name", me)) && !objectp(ob2 = present("tian jing", me))
            ||      !ob2->is_qiling_ob() )
            return notify_fail("你好象還沒備齊無名之物或寰宇天晶吧？\n");

        type = query("type", ob1);  // 裝備之魂部位

        if(ob->is_weapon() )
        {
            if(type != "weapon" )
                return notify_fail("啟靈"+ob->name() + NOR"需要武器之魂！\n");
        }
        else
        {
            if(type != query("armor_type", ob) )
                return notify_fail("啟靈"+ob->name() + NOR"需要"+query("armor_type", ob) + "之魂！\n");
        }

        status = query("status", ob1);  // 裝備之魂等級

        if(status <= qlvl )
            return notify_fail("你的裝備之魂等級不夠，無法用來給"+ob->name() + NOR"啟靈！\n");
    }

    if(query("balance", me) < 1000000000 )
        return notify_fail("你的銀行存款不足，啟靈費用需要十萬兩黃金。\n");

    if(ob1->is_spe_crystal() )
    {
        if(ob->is_weapon() ) type = "weapon";
        else type = query("armor_type", ob);
    }

    if(qlvl == 1 ) success = 80;
    else if(qlvl == 2 ) success = 70;
    else if(qlvl == 3 ) success = 40;
    else if(qlvl == 4 ) success = 20;
    else if(qlvl == 5 ) success = 10;

    success += (status - qlvl) * 10;

    if(objectp(ob2) && query("id", ob2) == "tian jing" )
        success += 20;

    else if(objectp(ob2) && query("id", ob2) == "no name" )
        success += 30;

    if(random(100) < success )
    {
        if(objectp(ob1) && ob1->is_spe_crystal() && query("qiling_level", ob1) == qlvl + 1 )
            delete("qiling_level", ob1);    // 消除超能力水晶上啟靈等級的記錄

        addn("qiling/apply_prop/max_jing", 1000*(qlvl + 1), ob);    // 增加精
        addn("qiling/apply_prop/max_qi", 2000*(qlvl + 1), ob);  // 增加氣

        addn("status", 1, ob);

        if(type == "rings" || type == "neck" || type == "charm" )
        {
            addn("qiling/apply_prop/research_effect", 5, ob);
            addn("qiling/apply_prop/derive_effect", 5, ob);
            addn("qiling/apply_prop/practice_effect", 5, ob);
        }

        tell_object(me, HIC "你感受" + ob->name() + HIC "發生了不可言喻的變化。\n" NOR);
        if(query("status", ob) == 6 )
        {
            if(type == "rings" || type == "neck" || type == "charm" )
            {
                addn("qiling/apply_prop/research_effect", 25, ob);
                addn("qiling/apply_prop/derive_effect", 25, ob);
                addn("qiling/apply_prop/practice_effect", 25, ob);
                tell_object(me, HIC "成功開啟"+ob->name() + "靈智，" + ob->name() + HIC "的研究、汲取、練習的效果提高了3%。\n" NOR);
            }
            else if(ob->is_weapon() || ob->is_unarmed_weapon() )
            {
                data = query("qiling/apply_prop", ob);
                data["fatal_blow"] = 10;
                data["leech_qi"] = 20;
                data["leech_neili"] = 20;
                set("qiling/apply_prop", data, ob);

                tell_object(me, HIC "成功開啟"+ob->name() + "靈智，" + ob->name() + HIC "擁有致命一擊屬性。\n" NOR);
            }
            else
            {
                data = query("qiling/apply_prop", ob);
                data["full_self"] = 5;
                data["avoid_die"] = 5;
                set("qiling/apply_prop", data, ob);

                tell_object(me, HIC "成功開啟"+ob->name() + "靈智，" + ob->name() + HIC "擁有戰神附體和浴血重生屬性。\n" NOR);
            }
            /*
             * data=query("weapon_prop", ob);
             * if( !mapp(data) ) data = query("armor_prop", ob);
             * apply = keys(data);
             * for(i=0; i<sizeof(apply); i++)
             * set("qiling/apply_prop", data[apply[i]] * 2, ob); // 屬性不重複
             */
            if(query("weapon_prop/damage", ob) )
                set("qiling/apply_prop/damage", query("weapon_prop/damage", ob) * 2, ob);   // 屬性不重複
            if(query("armor_prop/unarmed_damage", ob) )
                set("qiling/apply_prop/unarmed_damage", query("armor_prop/unarmed_damage", ob) * 2, ob);    // 屬性不重複
            if(query("armor_prop/armor", ob) )
                set("qiling/apply_prop/armor", query("armor_prop/armor", ob) * 2, ob);  // 屬性不重複

            addn("enchase/flute", 1, ob);
            CHANNEL_D->do_channel(this_object(), "chat", HIC "不想千年之後，終於見到傳說中的具有靈智的神器，實在是死而無憾也！\n" NOR);
        }
        ob->save();
        MYGIFT_D->check_mygift(me, "newbie_mygift/qiling");
    }
    else
        tell_object(me, HIW "很遺憾，啟靈失敗。\n" NOR);

    addn("balance", -1000000000, me);

    if(objectp(ob1) && !ob1->is_spe_crystal() )
    {
        destruct(ob1);
        if(objectp(ob2) ) destruct(ob2);
    }
    ob->save();
    return 1;
}

void kill_ob(object ob) {
    ::kill_ob(ob);
    message_vision("$N冷笑一聲，道：“這年頭，什麼人都有。”說完伸手一指$n。\n",
        this_object(), ob);
    ob->unconcious();
}

int accept_fight(object who) {
    command("say 沒興趣。");
    return 0;
}

int accept_ansuan(object who) {
    return notify_fail("你剛想暗算，可是眼前一花，看不太清楚。\n");
}

varargs int receive_damage(string type, int n, object who) {
    return 0;
}

varargs int receive_wound(string type, int n, object who) {
    return 0;
}
