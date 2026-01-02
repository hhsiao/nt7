// This program is a part of NT MudLIB
// redl 2014
// 九老洞持鑰匙波陀摩花者

#include <ansi.h>

inherit BOSS;

void del_busy();
int hand_throw();

int get_helpkill() {
    object me = this_player(), ob = this_object();

    if (ob->is_fighting() || ob->is_busy()) {
        tell_object(me, CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：沒見我正在忙嗎？\n"+ NOR);
        return 1;
    }

    if(query("level", me) < 150){
        tell_object(me, CYN + query("name") + NOR + CYN + "面孔扭曲地說：就閣下這小身板也想除魔？是想坑我去送死吧...\n"+ NOR);
        return 1;
    }

    if (time() - query("jldong/killshu_time", me) < 600) {
        message_vision(CYN + query("name") + NOR + CYN + "憤怒地對$N說道：幾分鐘前才見你殺害我的同門姐妹，賊子，拿命來！\n"+ NOR, me);
        ob->kill_ob(me);
        return 1;
    }

    if(query("flag_go1") ){
        tell_object(me, CYN + query("name") + NOR + CYN + "面孔扭曲地說：我不是已經在幹活兒了嘛...\n"+ NOR);
        return 1;
    }

    if (!query("flag_helpkill") || query("flag_helpkill")!= query("id", me)) {
        tell_object(me, CYN + query("name") + NOR + CYN + "悄悄在你耳邊說道：我最近想收集寰宇天晶來打造仙劍，真是頭疼呀...\n"+ NOR);
        return 1;
    }

    message_vision(CYN + query("name") + NOR + CYN + "深深地打量了$N一眼說：我就暫且信你，我先去也，趕緊跟上來，我時間有限哦。\n"+ NOR +
        query("name") + NOR + YEL + "說完掐了個劍訣，緊抿嘴皮用力頓足，乘著一道劍光沖天而去。\n" + NOR, me);
    ob->move("/d/emei/xue/bfde0", 1);
    set("max_qi", query("max_qi") * 60);
    set("max_jing", query("max_jing") * 60);
    addn("level", query("level", me) / 2);
    set("n_flee", 2700);    //45分鐘銷燬
    set("flag_go1", 1);
    return 1;
}


int accept_object(object me, object obj) {
    object ob = this_object();

    if (ob->is_fighting() || ob->is_busy()) {
        tell_object(me, CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：沒見我正在忙嗎？\n"+ NOR);
        return 1;
    }

    switch (query("id", obj))
    {
    case "tianshi charm":
        if (query("my_life") < 5) {
            message_vision(CYN + query("name") + NOR + CYN + "接過$N的天師符，道謝後放在了懷裡。\n"+ NOR, me);
            addn("my_life", 1);
            destruct(obj);
            return 1;
        } else {
            tell_object(me, CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：我現在還不需要這個東西。\n"+ NOR);
            return 0;
        }
    case "tian jing":
        if (base_name(obj) == "/clone/goods/tianjing") {
            message_vision(CYN + query("name") + NOR + CYN + "接過$N的寰宇天晶，道謝後放在了懷裡。\n"+ NOR, me);
            set("flag_helpkill", query("id", me));
            destruct(obj);
            return 1;
        } else {
            tell_object(me, CYN + query("name") + NOR + CYN + "慢悠悠地對你說道：這個東西是高仿的嗎？\n"+ NOR);
            return 0;
        }
    default:
        return 0;
    }

}

int is_home(string where) {
    if (strsrch(where, "/bfdb") != -1) return 1;
    if (strsrch(where, "/bfdc") != -1) return 1;
    return 0;
}

int random_move() {
    mapping exits;
    string *dirs, direction, to_go_place;
    object env;
    if(!mapp(exits = query("exits", environment())))return 0;
    if (query("flag_helpkill")) {
        command("ask " + query("flag_helpkill") + " about gogogo..");
        command("go north");
        return 1;
    }
    dirs = keys (exits);
    direction = dirs[random(sizeof(dirs))];
    env = environment(this_object());
    to_go_place = query("exits/"+direction, env);
    if (!is_home(to_go_place)) return 0;
    if (!random(20)) command("get all");
    command("go " + direction);
    return 1;
}


void create() {
    switch (random(4)) {
    case 0:
        set_name(CYN "鄧八姑" NOR, ({ "deng bagu", "jianxia", "deng" }) );
        break;
    case 1:
        set_name(CYN "秦紫玲" NOR, ({ "qin ziling", "jianxia", "qin" }) );
        break;
    case 2:
        set_name(CYN "易靜" NOR, ({ "yi jing", "jianxia", "yi" }) );
        break;
    case 3:
        set_name(CYN "籟姑" NOR, ({ "lai gu", "jianxia", "lai" }) );
        break;
    }
    set("title", HIG "蜀山" HIC "劍俠" NOR);
    set("long", HIR "這是傳說中的蜀山弟子，專程到此除魔修煉。\n" NOR);

    set("gender", "女性");
    set("age", 25);

    set("str", 900);
    set("int", 900);
    set("con", 900);
    set("dex", 900);
    set("shen", 6000000);
    set_temp("apply/attack", 900000);
    set_temp("apply/unarmed_damage", 100000);
    set_temp("apply/damage", 100000);
    set_temp("apply/armor", 50000);

    set("max_qi", 20000000000);
    set("eff_qi", 20000000000);
    set("qi", 20000000000);
    set("max_jing", 10000000000);
    set("jing", 10000000000);
    set("eff_jing", 10000000000);
    set("max_jingli", 500000000);
    set("jingli", 500000000);
    set("neili", 500000000);
    set("max_neili", 500000000);
    set("jiali", 10000);
    set("combat_exp", 5000000000);
    set("level", 100 + random(30));

    set_skill("unarmed", 20000);
    set_skill("finger", 20000);
    set_skill("claw", 20000);
    set_skill("strike", 20000);
    set_skill("hand", 20000);
    set_skill("cuff", 20000);
    set_skill("parry", 20000);
    set_skill("dodge", 20000);
    set_skill("force", 20000);
    set_skill("sword", 20000);
    set_skill("blade", 20000);
    set_skill("throwing", 20000);
    set_skill("zuoyou-hubo", 1000);

    set_skill("lonely-sword", 10000 + random(9999));
    set_skill("jiuyang-shengong", 10000 + random(9999));
    set_skill("yinyang-shiertian", 10000 + random(9999));
    set_skill("tanzhi-shentong", 10000 + random(9999));
    set_skill("qiankun-danuoyi", 8000 + random(4000));
    set_skill("martial-cognize", 10000 + random(5000));
    set_skill("count", 3000 + random(3000));
    set_skill("lingbo-weibu", 10000 + random(9999));
    set_skill("literate", 5000);
    set_skill("huajia-su", 1500);
    set_skill("jingluo-xue", 5000);

    //set("no_nuoyi", 1); // 不被挪移影響
    set("yuanshen", 1);     //無招
    set("lonely-sword/nothing", 1);     //無招
    set("yinyang-shiertian/shier", 12);
    set("yinyang-shiertian/yinyang", 12);
    set("yinyang-shiertian/qiankun", 12);

    map_skill("parry", "qiankun-danuoyi");
    map_skill("force", "yinyang-shiertian");
    map_skill("dodge", "lingbo-weibu");
    map_skill("unarmed", "yinyang-shiertian");
    map_skill("finger", "tanzhi-shentong");
    map_skill("throwing", "tanzhi-shentong");
    map_skill("strike", "yinyang-shiertian");
    map_skill("hand", "yinyang-shiertian");
    map_skill("cuff", "yinyang-shiertian");
    map_skill("claw", "yinyang-shiertian");
    map_skill("sword", "lonely-sword");

    prepare_skill("finger", "tanzhi-shentong");

    set("can_perform/qiankun-danuoyi/yi", 1);
    set("can_perform/lonely-sword/yi", 1);
    set("can_perform/lonely-sword/po", 1);
    set("can_perform/lonely-sword/jian", 1);
    set("can_perform/lonely-sword/qi", 1);
    set("can_perform/tanzhi-shentong/ding", 1);
    set("can_perform/tanzhi-shentong/dian", 1);
    set("can_perform/tanzhi-shentong/po", 1);

    set("chat_chance", random(7) + 3);
    set("chat_msg", ({
        (: random_move :),
        (: random_move :),
        (: command("kill xixue bianfu") :),
        (: command("kill xixue bianfu") :),
        (: command("kill xixue bianfu") :),
        (: command("say 如果我有充足的天師符，對上那老魔時倒也穩當了許多。") :)
    }));

    // yun perform
    set("chat_chance_combat", 105);
    set("chat_msg_combat", ({
        (: command("perform sword.jian") :),
        (: command("perform sword.qi and sword.yi") :),
        (: command("perform sword.po and sword.yi") :),
        (: command("perform sword.po and sword.qi") :),
        (: command("perform finger.dian and finger.ding") :),
        (: command("perform finger.po and finger.ding") :),
        (: command("perform finger.po and finger.dian") :),
        (: command("perform finger.po and parry.yi") :),
        (: command("perform parry.yi and parry.yi") :),
        (: exert_function, "powerup": ),
        (: exert_function, "shield": ),
        (: exert_function, "recover": ),
        (: exert_function, "dispel": ),
        (: del_busy :),
        (: command("kill xixue bianfu " + (string)(random(9) + 1)) :)
    }));

    set("my_life", 1);  // 當氣血低於10%的時候補滿一次，設置該參數為0

    //set("auto_perform", 1);
    //set("end_time", 60);  // 必須戰鬥不少於60秒後死亡
    set("rewards", ([
        "exp": 250000,
        "pot": 125000,
        "mar": 50000,
        "weiwang": 10000,
        "score": 10000,
        "gold": 10000
        ]));

    set("drops", ([
        "FI&/clone/medal/diamond_xunzhang"       : 7,
        "FI&/clone/medal/yongshi_xunzhang"      : 20,
        "FI&/clone/fam/max/longjia"       : 100
        ]));

    set_temp("apply/reduce_damage", 75);
    set_temp("apply/reduce_busy", 32);
    set_temp("apply/add_busy", 5);
    set_temp("apply/add_poison", 50);

    set("inquiry", ([
        "除魔" : (: get_helpkill :)
        ]));

    set("n_flee", 3600);
    setup();

    set("hand_throwing", "/d/chengdu/npc/obj/flower-leaf");
    carry_object("/kungfu/class/quanzhen/obj/greyrobe")->wear();
    carry_object(__DIR__"obj/hairpin")->wear();
    carry_object(__DIR__"obj/xijian")->wield();
    hand_throw();

    //        set("startroom", "/d/jianzhong/maigu");
}

int hand_throw() {
    object ob, me = this_object();

    if (query_temp("handing")) return 1;
    if (!query("hand_throwing")) return 1;

    ob = new(query("hand_throwing"));
    if(ob->query_amount() ) {
        ob->set_amount(999);
    }

    ob->move(me, 1);
    command("hand " + query("id", ob));
    return 1;
}

void heart_beat() {
    object me = this_object();
    if(query("n_flee") < 1 ){
        message_vision(CYN + query("name") + NOR + CYN + "仰天長嘆：看來此番魔道氣數未盡，罷了，罷了...\n"+ NOR +
            query("name") + NOR + YEL + "說完掐了個劍訣，緊抿嘴皮用力頓足，乘著一道劍光沖天而去。\n" + NOR, me);
        destruct(this_object());
        return;
    }
    addn("n_flee", -1);
    if (random(3) == 1)
    {
        delete_temp("no_perform");
        delete_temp("no_exert");
        hand_throw();
    }
    if (!this_object()->is_fighting() && !random(10)) {
        me->stop_busy();
        command("halt");
        me->stop_busy();
        command("yun powerup");
        me->stop_busy();
        full_self();    // 補滿氣血
    }
    return ::heart_beat();
}

void del_busy() {
    object me = this_object();
    if (random(8)) return;
    if (me->is_busy()) me->interrupt_busy(me, 1000);
    if (me->is_busy()) me->interrupt_me(me);
    if (me->is_busy()) me->stop_busy();
    if (me->is_busy()) me->interrupt_busy(me);
}

int accept_hit(object me) {
    this_object()->kill_ob(me);
    return 1;
}

int accept_fight(object me) {
    this_object()->kill_ob(me);
    return 1;
}

int accept_kill(object me) {
    this_object()->kill_ob(me);
    return 1;
}

void new_life() {
    full_self();    // 補滿氣血
    del_busy();
    delete_temp("no_perform");
    delete_temp("no_exert");

    addn_temp("apply/attack", query_temp("apply/attack") * 2);
    addn_temp("apply/unarmed_damage", query_temp("apply/unarmed_damage") / 2);
    addn_temp("apply/damage", query_temp("apply/damage") / 2);
    addn_temp("apply/armor", query_temp("apply/armor") * 2);

    addn("my_life", -1);
    message_vision(HIG "\n$N" HIG "嬌呼一聲燃起天師符，瞬間神光四湛！\n\n" NOR, this_object());
    return;
}

int receive_damage(string type, int damage, object who) {
    object *ppl;

    if(!who ) who = this_object()->query_last_damage_from();
    if(!who ) return;
    ppl = query_temp("damage_from");
    if(!arrayp(ppl) || !sizeof(ppl) ) ppl = ({});
    if(userp(who) && member_array(who, ppl) == -1 )
    {
        ppl += ({ who });
        set_temp("damage_from", ppl);
    }

    if (query("my_life") && query("qi") < query("max_qi") / 10)
    {
        new_life();     // 重生一次
        return 0;
    }

    return ::receive_damage(type, damage, who);
}

void die(object killer) {
    object ob;
    /*
     * string *apply = ({ "reduce_busy", "avoid_busy", "def_damage", "avoid_weak",
     * "add_locked", "reduce_damage", "add_busy", "add_weak", "avoid_locked",
     * "add_damage", "add_skill" });*/

    if(objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") )
    {
        full_self();
        return;
    }

    if(!objectp(killer) ) killer = this_object()->query_last_damage_from();
    if(!objectp(killer) ) killer = query_temp("last_damage_from");

    // 如果還未重生，則重生一次
    if (query("my_life"))
    {
        new_life();
        return;
    }

    if(time() < query_temp("end_time") )    // 時間沒有到，死亡不了
    {
        addn("jing", query("max_jing") / 10);
        if(query("jing") > query("max_jing") ) set("jing", query("max_jing"));
        addn("eff_jing", query("max_jing") / 10);
        if(query("eff_jing") > query("max_jing") ) set("eff_jing", query("max_jing"));
        addn("qi", query("max_qi") / 10);
        if(query("qi") > query("max_qi") ) set("qi", query("max_qi"));
        addn("eff_qi", query("max_qi") / 10);
        if(query("eff_qi") > query("max_qi") ) set("eff_qi", query("max_qi"));
        //message_vision(HIR "\n$N" HIR "大喝一聲，運用秘法，氣血有所回升！\n\n" NOR, this_object());
        return;
    }

    if (new(__DIR__"obj/hairpin")->move(killer, 1)) {
        message_vision(HIR "叮~~一聲，從$N" HIR "掉出一朵血紅的花，$n" HIR
            "趕緊揀起來揣到懷裡。\n" NOR, this_object(), killer);
        set("jldong/killshu_time", time() , killer);
    }

    return ::die(killer);
}

varargs void unconcious(object defeater)
{
    object ob;

    //if( query("end_boss") || query("fight_boss") )
    if(objectp(ob = previous_object(0)) && sscanf(base_name(ob), "/kungfu/skill/%*s") ) {
        full_self();
        return;
    }
    die(defeater);
    return;
}

/*
 * // 不會被busy
 * varargs void start_busy(mixed new_busy, mixed new_interrupt)
 * {
 * return;
 * }*/
