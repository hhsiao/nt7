// This program is a part of NITAN MudLIB
// redl 2013/5
#include <armor.h>
#include <ansi.h>

inherit EARRING;

#define TIME_INTERVAL 10        //BONUS_DELAY必須是這裡的整數倍，且大於640
#define BONUS_DELAY 2160        //一天40次
#define BONUS_EXP 750000        //每次獎勵exp


void jieguozi()
{
        object own = environment(this_object());

        int i = query("guozi_step");
                if ( objectp(own) && playerp(own) && (query("id", own) == query("me_id")) && query("equipped") == "worn" ) {
                        i -= TIME_INTERVAL;
                        if (i<1) {
                                //tell_object(own, NOR + YEL + "只見" + HIG + "七寶妙樹．耳環" + NOR + YEL + "上，花瓣零落，露出幾枚晶瑩透綠的果實。\n$N伸手輕輕摘下果實，得到了七種珍寶！\n" + NOR);
                                if (!random(3)) new("/clone/tessera/diamond")->move(own);
                                if (!random(3)) new("/clone/tessera/emerald")->move(own);
                                if (!random(3)) new("/clone/tessera/sapphire")->move(own);
                                if (!random(3)) new("/clone/tessera/ruby")->move(own);
                                if (!random(3)) new("/clone/tessera/topaz")->move(own);
                for(int i2 = 10; i2 > 0; i2--) {
                        new("/clone/gift/xuanhuang")->move(own);
                }
                                new("/clone/medicine/yuqingwan")->move(own);
                        addn("combat_exp", BONUS_EXP, own);
                                addn("yuanshen_exp", BONUS_EXP / 4, own);
                        addn("potential", BONUS_EXP / 4, own);
                        addn("experience", BONUS_EXP / 8, own);
//                              call_other(GIFT_D, "bonus", own, ([ "exp":BONUS_EXP, "pot":BONUS_EXP/4, "mar":BONUS_EXP/8, "prompt":"你在七寶妙樹下參悟了大道法則之後"]));
                        }
//                      else if (i==30) tell_object(own, NOR + YEL + "你看見" + HIG + "七寶妙樹．耳環" + NOR + YEL + "上，菩提花開始漸漸凋謝……\n" + NOR);
//                      else if (i==120) tell_object(own, NOR + YEL + "你看見" + HIG + "七寶妙樹．耳環" + NOR + YEL + "上，花苞慢慢長大，變成了豔麗的紅蓮花。\n" + NOR);
//                      else if (i==360) tell_object(own, NOR + YEL + "你看見" + HIG + "七寶妙樹．耳環" + NOR + YEL + "上，嫩黃色的花骨朵長出來了。\n" + NOR);
//                      else if (i==640) tell_object(own, NOR + YEL + "你看見" + HIG + "七寶妙樹．耳環" + NOR + YEL + "上，悄悄鑽出了一點嫩黃色。\n" + NOR);
                        if (i<1) set("guozi_step", BONUS_DELAY);
                                else set("guozi_step", i);
                }

        call_out("jieguozi", TIME_INTERVAL);

        if (  objectp(own) && query("me_id") )
                if (query("id", own) != query("me_id")) destruct(this_object());//非主人身上時
                else if (!query("env/invisible_item", own)) destruct(this_object());//主人沒有設置隱藏時
}

void create()
{
        set_name(HIR "紫金花耳環" NOR, ({ "zijinhua erhuan3", "qibao miaoshu", "qibao", "erhuan" }));
        set_weight(100);
                set("unit", "枚");
//                 set("long", HIG "七寶妙樹．耳環，這是用老祖證道的菩提樹枝所制，象徵著如海的智慧。\n" NOR);
                 set("long", HIR "這是一枚耳環。\n" NOR);
                set("value", 500000000);
                set("material", "gold");
                set("armor_prop/str", 100);
                set("armor_prop/int", 200);
                set("armor_prop/con", 100);
                set("armor_prop/dex", 100);
                set("armor_prop/armor", 10000);
                //set("armor_prop/armor1", 10000);
                set("armor_prop/damage", 5000);
                //set("armor_prop/damage1", 5000);
                set("armor_prop/unarmed_damage", 5000);
                set("armor_prop/attack", 1000);
                set("armor_prop/defense", 1000);
                                set("armor_prop/research_times", 300);
                set("armor_prop/research_effect", 300);
                set("armor_prop/practice_times", 300);
                set("armor_prop/practice_effect", 300);
                set("armor_prop/learn_times", 300);
                set("armor_prop/learn_effect", 300);
                set("armor_prop/derive_times", 300);
                set("armor_prop/derive_effect", 300);
                set("armor_prop/full_self", 20);
                set("armor_prop/reduce_poison", 30);
                //set("armor_prop/add_locked", 10);
                //set("armor_prop/avoid_locked", 20);
                set("armor_prop/fatal_blow", 10);
                set("armor_prop/add_skill", 180);
                set("armor_prop/avoid_die", 25);
                set("armor_prop/avoid_blind", 90);
                set("armor_prop/ap_power", 50);
                set("armor_prop/dp_power", 60);
                set("armor_prop/da_power", 40);
                set("armor_prop/avoid_busy", 25);
                set("armor_prop/reduce_busy", 20);
                set("armor_prop/max_qi", 300000);
                set("armor_prop/max_jing", 200000);
                set("armor_prop/max_neili", 800000);
                set("armor_prop/max_jingli", 600000);
                set("no_uget", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_sell", 1);
                set("no_get", 1);
                set("no_steal", 1);
                set("no_beg", 1);
                set("no_put", 1);
                set("no_store", 1);
                set("guozi_step", BONUS_DELAY);
        setup();
        call_out("jieguozi", TIME_INTERVAL);
}

int wear()
{
        object me = this_player();
        if (query("id", me) != query("me_id")) {
                tell_object(me, NOR + "你不能佩戴這種特殊物品！\n" + NOR);//不許普通玩家非法穿戴變態屬性的物品
                return -1;
        }
        if (::wear()) {
                //message_vision(YEL + "$N輕輕捻起一枚" + NOR + query("name") + NOR + YEL + "戴在耳垂上。\n" + NOR, me);
                return 1;
        }
}

int do_name(string arg)//授權
{
        object me;
        me = this_player();
        if (! wizardp(me)) return 0;
        if (! arg) return notify_fail("name id!\n");

                me = find_player(arg);
                if (!me || !objectp(me) || !playerp(me)) {
                        write("你目前沒有發現這玩家在線。\n");
                        return 1;
                }

                set("bindable", 3);
                set("bind_owner",query("id",  me));
        set("me_id", arg);
                set("set_data", 1);
                set("auto_load", 1);
        set("env/invisible_item", 1, me);
        this_object()->move(me);
        tell_object(me, "你獲得了特殊裝備七寶妙樹，look erhuan\n不要丟棄或者展示給他人，否則它會消失。\n");
        write("七寶妙樹被設為" + arg + "專用的！\n");
        return 1;
}

void init()
{
        add_action("do_name", "name");
}
