#include <ansi.h>

#define MEMBER_D "/adm/daemons/memberd"
#define MAX_POINT 100
#define TAOZHUANG_D "/adm/daemons/taozhuangd"
#define DB_D "/adm/daemons/dbd"

inherit NPC;

void damage_all();
void check_weapon();


string *force_list = ({
    "jiuyang-shengong",
    "beiming-shengong",
    "jiuyin-shengong",
    "xiantian-gong",
    "hunyuan-yiqi",
    "shennong-xinjing",
    "yijinjing",
    "linji-zhuang",
    "xiuluo-yinshagong",
    "zhanshen-xinjing",
    "bluesea-force",
    "huagong-dafa",
    "never-defeated",
    "surge-force",
    "yijin-duangu",
    "bingxin-jue",
    "hanbing-zhenqi",
    "kuihua-mogong",
    "shenzhaojing",
    "zihui-xinfa",
    "shenghuo-shengong",
    "bahuang-gong",
    "yunv-xinjing",
    "xuanming-shengong",
    "jiuyin-hamagong",
    "emei-jiuyang",
    "shaolin-jiuyang",
    "wudang-jiuyang",
    "kurong-changong",
    "xuedao-dafa",
    "hama-gong",
    "liangyi-shengong",
    "xiaowuxiang"
});

string *dodge_list = ({

    "lingbo-weibu",
    "zhuangzi-wu",
    "beidou-xianzong",
    "shexing-lifan",
    "tan-tui",
    "piaoyi-bu",
    "yiwei-dujiang",
    "shaolin-shenfa",
    "ruying-suixingtui",
    "xuanfeng-tui",
    "tiyunzong",
    "sixiang-bufa",
    "zhaixing-gong",
    "beidou-xianzong",
    "feixing-shu"
});

string *unarmed_list = ({
    "dafumo-quan",
    "taiji-quan",
    "sad-strike",
    "xuangong-quan"
});


// 來自於天書OB調用，初始化BOSS
void init_data(string skybookOBPath, string sGender, string sID, string sName, int nHp, int nDamage, int nDefense, string sSkill, int nSkLevel, string sType, string sNandu) {

    string skforce, skdodge, skunarmed;
    string sWeapon;
    mixed *mFile;
    string *performs;
    int i;

    set("age", 9999);
    set("gender", sGender);
    set("skybookOBPath", skybookOBPath);
    set_name(sName, ({ sID }));
    set("title", HIY + query("books") + NOR);

    set_temp("apply/attack", 100000000);
    set_temp("apply/unarmed_damage", nDamage);
    set_temp("apply/damage", nDamage);
    set_temp("apply/armor", nDefense);

    set("max_qi", nHp);
    set("eff_qi", nHp);
    set("qi", nHp);


    set_skill("unarmed", nSkLevel);
    set_skill("finger", nSkLevel);
    set_skill("claw", nSkLevel);
    set_skill("strike", nSkLevel);
    set_skill("hand", nSkLevel);
    set_skill("cuff", nSkLevel);
    set_skill("parry", nSkLevel);
    set_skill("dodge", nSkLevel);
    set_skill("force", nSkLevel);
    set_skill("sword", nSkLevel);
    set_skill("blade", nSkLevel);
    set_skill("zuoyou-hubo", 2500);


    // 隨機選取內功，輕功，拳腳
    skforce = force_list[random(sizeof(force_list))];
    skdodge = dodge_list[random(sizeof(dodge_list))];
    skunarmed = unarmed_list[random(sizeof(unarmed_list))];

    set_skill(skforce, nSkLevel);
    set_skill(skdodge, nSkLevel);
    set_skill(skunarmed, nSkLevel);
    set_skill(sType, nSkLevel);
    set_skill(sSkill, nSkLevel);
    set_skill("martial-cognize", nSkLevel);

    map_skill("force", skforce);
    map_skill("dodge", skdodge);
    map_skill("unarmed", skunarmed);
    map_skill("parry", sSkill);
    map_skill(sType, sSkill);

    if (sType == "sword" || sType == "blade" || sType == "whip")
    {

        if (sType == "sword")sWeapon = "changjian";
        if (sType == "blade")sWeapon = "blade";
        if (sType == "whip")sWeapon = "changbian";
        // 武器
        carry_object("/clone/weapon/" + sWeapon)->wield();

        set("weapon_path", "/clone/weapon/" + sWeapon);

        prepare_skill("unarmed", skunarmed);
    }
    else
    {
        prepare_skill(sType, sSkill);

    }

    // 衣服
    carry_object("/clone/cloth/cloth")->wear();

    // 從主技能目錄選取perform
    mFile = BACKUP_D->get_dir_by("/kungfu/skill/" + sSkill + "/", -1);

    for (i = 0; i < sizeof(mFile); i ++)
    {
        if (mFile[i][0] == "perform" && mFile[i][1] == -2)  // 存在perform目錄
        {
            mFile = BACKUP_D->get_dir_by("/kungfu/skill/" + sSkill + "/perform/", -1);
            break;
        }
    }

    performs = ({});

    for (i = 0; i < sizeof(mFile); i ++)
    {
        if (mFile[i][1] != -2)
            performs += ({ (: perform_action, sType + "." +  replace_string(mFile[i][0], ".c", "") :) });
    }
    // yun perform
    set("chat_chance_combat", 120);
    set("chat_msg_combat", performs + ({

        (: exert_function, "powerup": ),
        (: exert_function, "shield": ),
        (: exert_function, "recover": ),
        (: exert_function, "dispel": ),
        (: check_weapon :),

    }));


    set("env", environment(this_object()));

    setup();
}

void create() {
    set_name("NONE", ({ "SKYBOOKOB" }) );

    set("str", 800);
    set("int", 800);
    set("con", 800);
    set("dex", 800);

    set("shen", 0);

    set_temp("apply/qy", 70);   // 氣運
    set_temp("apply/fy", 70);   // 福緣

    set("scborn/ok", 1);


    set("max_jing", 1000000000);
    set("jing", 1000000000);
    set("eff_jing", 1000000000);
    set("max_jingli", 1000000000);
    set("jingli", 1000000000);

    set("neili", 200000000);
    set("max_neili", 1000000);
    set("jiali", 50000);
    set("combat_exp", 2100000000);



    set_skill("martial-cognize", 5000);
    set_skill("literate", 5000);
    set_skill("jingluo-xue", 5000);

    set("no_nuoyi", 1);     // 不被挪移影響
    set("can_learn/dugu-jiujian/nothing", 1);   //無招
    set("yinyang-shiertian/shier", 12);
    set("yinyang-shiertian/yinyang", 12);
    set("yinyang-shiertian/qiankun", 12);



    set("my_life", 0);  // 當氣血低於10%的時候補滿一次，設置該參數為0

    setup();
}

void heart_beat() {
    int nRan;

    keep_heart_beat();

    // 解除不能perform yun的限制
    if (random(3) == 1)
    {
        delete_temp("no_perform");
        delete_temp("no_exert");
    }
    if (random(5) == 1)check_weapon();

    // 每30秒恢復氣血
    if (query("last_full_time") == 0)set("last_full_time", query("create_time"));
    if (time() - query("last_full_time") >= 30)
    {
        set("last_full_time", time());

        if (query("難度") == "少俠級")
        {
            nRan = 5 + random(6);
        }
        else if (query("難度") == "大俠級")
        {
            nRan = 10 + random(16);
        }
        else
        {
            nRan = 20 + random(11);
        }

        add("eff_qi", query("max_qi") / 100 * nRan);
        if (query("eff_qi") > query("max_qi"))
            set("eff_qi", query("max_qi"));
        set("qi", query("eff_qi"));

        message_vision(HIG "\n突然一陣金光籠罩，$N又似乎充滿了力量！\n", this_object());

    }


    return ::heart_beat();
}

// 檢查武器
void check_weapon() {
    object me, ob;

    me = this_object();

    // 同時補充內力
    set("neili", query("max_neili"));

    if (me->is_busy())me->interrupt_busy(me, 1000);

    if (me->is_busy())me->interrupt_me(me);

    if (! me->query_temp("weapon") && sizeof(query("weapon_path")))
    {
        ob = new(query("weapon_path"));
        ob->move(me);
        "/cmds/std/wield"->main(me, ob->query("id"));
    }

    if (random(10) == 1)
    {
        me->clear_condition();
    }

    // 很小几率恢復氣血
    if (random(200) == 1)
    {
        //log_file("qilin", ctime(time()) + " 成功恢復氣血。\n");
        if (me->query("eff_qi") < me->query("max_qi") / 3)me->add("eff_qi", me->query("max_qi") / 5);
        if (me->query("qi") < me->query("max_qi") / 3)me->add("qi", me->query("max_qi") / 5);
    }

    if (me->is_busy())me->interrupt_busy(me);


    // 如果所在地方不對了則摧毀
    if (environment(this_object()) != query("env"))
    {
        destruct(this_object());
    }

    return;
}

void init() {
    object me;

    me = this_player();

    //me->set("env/combatd", 4);
    //if (! wizardp(me))this_object()->kill_ob(me);
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
    object me = this_object();

    // 補滿氣血
    me->set("eff_qi", me->query("max_qi"));
    me->set("qi", me->query("max_qi"));
    me->set("eff_jing", me->query("max_jing"));
    me->set("jing", me->query("max_jing"));
    me->set("jingli", me->query("max_jingli"));

    me->clear_condition();

    me->interrupt_me(this_object());

    me->delete_temp("no_perform");
    me->delete_temp("no_exert");

    set_temp("apply/attack", 10000000);
    set_temp("apply/unarmed_damage", 400000);
    set_temp("apply/damage", 200000);
    set_temp("apply/armor", 100000);
    set_temp("apply/qy", 70);   // 氣運
    set_temp("apply/fy", 70);   // 福緣
    me->delete("my_life");

    message_vision(HIG "\n$N" HIG "長嘆一聲，全身紫氣大盛，竟突然恢復了戰鬥力！\n\n" NOR, me);

    return;
}

varargs int receive_wound(string type, int damage, object who) {
    if (! who) return 0;

    return ::receive_wound(type, damage, who);

}

varargs int receive_damage(string type, int damage, object who) {
    int tzlv;

    if (! who) return 0;

    // 套裝的追加傷害
    if (objectp(who))
    {
        tzlv = TAOZHUANG_D->taozhuang_level(who);

        if (tzlv == 3)  // 天驕
        {
            damage *= 2;
            this_object()->start_busy(5 + random(6));
            tell_object(HIM "「天驕套裝」追加傷害及附加忙亂！\n" NOR);
        }
        else if (tzlv == 4)
        {
            damage *= 3;
            start_busy(5 + random(6));
            tell_object(HIM "「無雙套裝」追加傷害及附加忙亂！\n" NOR);
            if (random(10) < 7)
            {
                set_temp("no_perform", 1);
                call_out("remove_no_perform", 10);
                tell_object(HIC "「無雙套裝」追加封招10秒！\n" NOR);
            }
        }
    }

    return ::receive_damage(type, damage, who);
}


void remove_no_perform() {
    delete_temp("no_perform");
}

void unconcious() {
    // 防止直接call_die()
    if (query("qi") > 2000000)
    {
        revive();
        return;
    }

    die(query_last_damage_from());
}

void die(object killer) {
    object dob;     // 打暈這個NPC的人

    object skybookob;


    // 防止直接call_die()
    if (query("qi") > 2000000)
    {
        revive();
        return;
    }

    // 如果還未重生，則重生一次
    if (query("my_life"))
    {
        new_life();
        return;
    }
    // 如果所在地方不對了則忽略
    if (environment(this_object()) != query("env"))
    {
        return;
    }

    // 找到殺了我(NPC)或是打暈我的人
    if (! objectp(dob = killer))
        dob = query_last_damage_from();
    if (! objectp(dob))
        dob = query_defeated_by();

    if (! dob)
    {
        dob = query("me");
    }


    // 我殺死了BOSS
    if (environment(dob) == query("born_room"))
    {
        if (! objectp(skybookob = find_object(query("skybookOBPath"))))
            skybookob = load_object(query("skybookOBPath"));

        // 完成副本通關
        if (query("nQuest") == dob->query("skybook14/" + query("books") + "/任務編號"))
        {
            int nKilltime, nMintime;
            string sQuest, sZhangjie, sTitle;

            // 記錄該副本最快通關時間和玩家
            sQuest = dob->query("skybook14/" + query("books") + "/任務編號");
            nMintime = DB_D->query_data("skybook/record/通關時間記錄/" + query("books") + "/" + sQuest + "/time");
            nKilltime = time() - query("create_time");
            if (nKilltime < nMintime || nMintime == 0)
            {
                DB_D->set_data("skybook/record/通關時間記錄/" + query("books") + "/" + sQuest + "/time", nKilltime);
                DB_D->set_data("skybook/record/通關時間記錄/" + query("books") + "/" + sQuest + "/id", dob->query("id"));
                DB_D->set_data("skybook/record/通關時間記錄/" + query("books") + "/" + sQuest + "/name", dob->query("name"));

                sZhangjie = skybookob->get_mSkybook_fuben(sQuest, 0);
                sTitle = skybookob->get_mSkybook_fuben(sQuest, 1);

                CHANNEL_D->do_channel(this_object(), "rumor", "聽說" + HIY + dob->query("name") + "(" + dob->query("id") + ")" HIM "創造了《" + query("books") + "》天書【" +
                    sZhangjie + "　" + sTitle + "】的最快通關記錄：" + sprintf("%d", nKilltime) + "秒！\n");
            }
            dob->set("skybook14/" + query("books") + "/任務編號", query("sNextQuest") );
            dob->set("skybook14/" + query("books") + "/當前章節", query("sNextQuestZhangjie"));
            dob->set("skybook14/" + query("books") + "/當前標題", query("sNextQuestTitle"));

            // 大結局特殊處理
            if (query("sNextQuestZhangjie") == "大結局")
            {
                skybookob->endskybook(dob);

                destruct(this_object());
                return;
            }
            else
            {
                mapping getmyskills;
                string *keys_myskills, *get2kskills, ssk;
                int i;

                message_vision(HIG + BLINK "\n副本通關，使用指令 " + HIC + "skybook start " + query("books") + HIG " 繼續副本 ！\n" NOR, dob, this_object());

                // 一定概率提升隨機技能一級
                getmyskills = dob->query_skills();
                if (sizeof(getmyskills) && random(10) < 2)
                {
                    keys_myskills = keys(getmyskills);
                    get2kskills = ({});
                    for (i = 0; i < sizeof(keys_myskills); i ++)
                        if (getmyskills[keys_myskills[i]] >= 1500 && ! SKILL_D(keys_myskills[i])->is_fmsk())
                        get2kskills += ({ keys_myskills[i] });

                    if (sizeof(get2kskills))    // 降低修養的獲得概率
                    {
                        ssk = get2kskills[random(sizeof(get2kskills))];
                        if (ssk == "martial-cognize" && random(10) < 3)ssk = get2kskills[random(sizeof(get2kskills))];  // 若是武學修養則再隨機抽取一次

                        dob->add_skill(ssk, 1);
                        log_file("0天書加技能.log", dob->query("id") + " " + ctime(time()) + " " + ssk + "\n");
                        tell_object(dob, HIG "\n恭喜你！技能" HIY + CHINESE_D->chinese(ssk) + HIG "等級提升1級。\n" NOR);
                    }
                }

                // 給予通關固定獎勵
                GIFT_D->delay_bonus(dob,
                    ([
                        "exp": 200000,
                        "pot": 200000,
                        "mar": 500000,
                        "prompt": "天書副本通關獎勵" ]), 999);
            }
        }

    }
    destruct(this_object());

    return;
}
