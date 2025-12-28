#include <ansi.h>
#include <medical.h>

inherit NPC;
inherit F_DEALER;

#define MAXQI 9999999999999

int ask_me();

void create()
{
        set_name(YEL"藥僮"NOR, ({ "yao tong", "yao", "tong" }));
        set("title", NOR CYN"傀儡商販"NOR);
        set("gender", "男性");
        set("age", 16);

        set("int", 30);

        set("qi", MAXQI);
        set("max_qi", MAXQI);
        set("jing", MAXQI);
        set("max_jing", MAXQI);
        
        set("combat_exp", MAXQI);
        set("attitude", "heroism");

        set_skill("unarmed", 99);
        set_skill("dodge", 99);
        set_skill("parry", 99);
        set_skill("force", 99);
        set_skill("liandan-shu", 600);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 50);

        set("inquiry", ([
                "療傷"   : (: ask_me  :),
                "heal"   : (: ask_me  :),
        ]));

        set("vendor_goods", ({
                HERB("chaihu"),         // 柴胡
                HERB("chenpi"),         // 陳皮
                HERB("chongcao"),       // 蟲草
                HERB("chuanwu"),        // 川烏
                HERB("dahuang"),        // 大黃
                HERB("dangui"),         // 當歸
                HERB("duhuo"),          // 獨活
                HERB("fangfeng"),       // 防風
                HERB("fuzi"),           // 附子
                HERB("gsliu"),          // 幹石榴
                HERB("guiwei"),         // 歸尾
                HERB("hafen"),          // 蛤粉
                HERB("heshouwu"),       // 何首烏
                HERB("honghua"),        // 紅花
                HERB("huangqi"),        // 黃芪
                HERB("lurong"),         // 鹿茸
                HERB("xiongdan"),       // 熊膽
                HERB("juhua"),          // 菊花
                HERB("lanhua"),         // 蘭花
                HERB("lingxian"),       // 靈仙
                HERB("lingzhi"),        // 靈芝
                HERB("mahuang"),        // 麻黃
                HERB("moyao"),          // 沒藥
                HERB("niuhuang"),       // 牛黃
                HERB("niuxi"),          // 牛膝
                HERB("qianjinzi"),      // 千金子
                HERB("renshen"),        // 人參
                HERB("ruxiang"),        // 乳香
                HERB("shadan"),         // 鯊膽
                HERB("shancha"),        // 山茶花
                HERB("shanjia"),        // 山甲
                HERB("shengdi"),        // 生地
                HERB("shenglg"),        // 生龍骨
                HERB("sumu"),           // 蘇木
                HERB("taoxian"),        // 桃仙
                HERB("tenghuang"),      // 藤黃
                HERB("tianqi"),         // 田七
                HERB("tugou"),          // 土狗
                HERB("wulingzhi"),      // 五靈脂
                HERB("xiefen"),         // 蠍粉
                HERB("xijiao"),         // 犀角
                HERB("xionghuang"),     // 雄黃
                HERB("xuejie"),         // 血竭
                HERB("xuelian"),        // 雪蓮
                HERB("yanwo"),          // 燕窩
                HERB("yjhua"),          // 洋金花
                HERB("yuanzhi"),        // 遠志
                HERB("zihua"),          // 紫花
                HERB("zzfen"),          // 珍珠粉
                HERB("hugu"),           // 虎骨
                "/clone/misc/dymo", 
                "/clone/drug/tianqi-san",
                "/d/city/obj/shanshen",
                "/clone/medicine/jinmisan",
                "/clone/book/medical_book",
        }));

        setup();
        carry_object("/clone/misc/cloth")->wear();
        set("neili", 0);
        set("max_neili", 0);
        set("jingli", 0);
        set("max_jingli", 0);
}

string getname()
{
        return NOR + CYN + query("name") + NOR ;
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void fullnow(object me)
{
        mapping my;
                me->remove_call_out("revive");
                me->remove_call_out("unconcious");
        my = me->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"]; 
        my["jingli"] = my["eff_jingli"] = my["max_jingli"]; 
        my["qi"]     = my["eff_qi"]     = my["max_qi"]; 
        my["neili"]  = my["max_neili"];
        me->clear_condition();
        me->stop_busy();
        me->clear_weak();
        me->full_self();
        if( query_temp("block_msg/all", me) ) {
                        tell_object(me, HIR "你終於抹掉了眼前的鮮血，能看見了。\n" NOR);
                        delete_temp("block_msg/all", me);
        }
}

int ask_me()
{
        object ob = this_player();
        
        if (ob->is_busy() || ob->is_fighting()) {
                write("你現在正忙。\n" NOR);
                return 1;
        }
        
        if (is_fighting() || is_busy()) {
                write(getname() + NOR + "沒空理你。\n" NOR);
                return 1;
        }
        
        if( query_temp("dongtian/healme", ob) > time() )
        {
                command("say 這麼快... 你又來？");
                command("slap " + query("id", ob));
                ob->start_busy(6);
        }
        else
        {
                message_vision(getname() + CYN + "手指微屈，單指一彈，一粒藥丸疾射入$N的咽喉，$N"
                                "不由“咕嚕”一聲吞入腹中，頓感神清氣爽，精神飽滿。\n", ob);
                                fullnow(ob);
                                set_temp("dongtian/healme", time() + 1800, ob);
                                ob->start_busy(3);
        }
        
                return 1;
}

int recognize_apprentice(object ob, string skill)
{
        if (skill != "liandan-shu")
                return 0;

        if (ob->query_skillo("liandan-shu", 1) >= 300)
        {
                write(getname() + CYN + 
                                "點了點頭，說道：煉丹技藝的提"
                        "高需要不斷從實踐中來提升的，煉丹技藝的\n"
                        "基本功我就教到這裡，剩下看你的天賦和修行了。\n" + NOR);
                return -1;
        }
        return 1;
}

varargs void die(object killer)
{
                message_vision(getname() + CYN + "手指微屈，單指一彈，一粒藥丸跳進嘴裡吞入腹中，頓感神清氣爽，精神飽滿。\n", this_object());
                                fullnow(this_object());
                return;
}

void unconcious()
{
    die();
        return;
}
