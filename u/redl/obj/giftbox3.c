// This program is a part of NITAN MudLIB 
// redl 2013/3
#include <ansi.h>
inherit ITEM;

#define EXPG 1000000

void create()
{
        set_name(NOR HIR"酒神"HIY"禮盒"NOR,({"box"}));
        set("long", HIY "這是一隻華麗的禮品盒子，不同等級的玩家可以獲得不同的禮品。你可以讓練功號（open box）打開它。\n" NOR HIK "(下線和扔掉會丟失，可以送人，趕快使用)\n" NOR); 
        set("unit", "些");
        set("base_unit", "個");
                //set("no_give","這樣東西不能離開你。\n");
                set("no_sell", "這樣東西不能離開你。\n");
                set("no_put", "這樣東西不能放在那兒。\n");
                set("no_store", "這樣東西不能放在那兒。\n");
                set("no_get", "這樣東西不能離開那兒。\n");
                set("no_steal", "這樣東西不能離開那兒。\n");
                set("no_beg", "這樣東西不能離開那兒。\n");
                set("base_value", 0);
                set("base_weight",1);
}

int give_ob(object me, object ob)
{
        ob->move(me, 1);
        tell_object(me, NOR + query("name") + NOR + "爆炸，你獲得了" + query("name", ob) + NOR + "。\n");
        return 1;
}
int drop_ob(object me, object ob)//不重要的，可能超重的東西扔地上
{
        ob->move(environment(me));
        tell_object(me, NOR + query("name") + NOR + "爆炸，你看見地上冒出了" + query("name", ob) + NOR + "。\n");
        return 1;
}

int do_open(string arg)
{
        object ob, me = this_player();
        int lv = query("level", me);
        string file = "/temp/qroom/" + query("id", me) + ".c";
        
        if (!arg || arg!="box") return 0;
        if( me->is_busy() ||
                me->is_fighting()
                ) {
                write(NOR BUSY_MESSAGE NOR);
                return 1;
        }
        if( query("doing", me) ) {
                write(NOR "你現在正在忙於鍛鍊，不能開禮盒。\n" NOR);
                return 1; 
        }
        if( !query("no_fight", environment(me)) ) {
                write(NOR "你必須在安全的地方才能開禮盒。\n" NOR);
                return 1; 
        }
        if(sizeof(filter_array(all_inventory(environment(me)), (: playerp :))) < 5) {
                write(NOR "你必須到人多熱鬧的地方(比如聊天室)去開禮盒。\n" NOR);//炫耀+監督
                return 1; 
        }
        
        me->start_busy(3);
        message_vision(NOR + CYN + "$N" + NOR + CYN + "抬手打開一個" + query("name") + NOR + 
                CYN + "，其中衝出青色霞光一卷，$N" + NOR + CYN + "消失了。\n" + NOR, me);

        if (!sizeof(get_dir("/temp/qroom"))) mkdir("/temp/qroom"); 
        if (!(load_object(file)))  
                cp("/u/redl/teleport/qroom.c", file); 
        me->move(file); //移到獨自空間，以免東西掉地上被撿取
        
                GIFT_D->work_bonus(me, ([ "prompt":"被福地霞光沖刷洗滌之後", "exp" : EXPG, "pot" : EXPG / 6 ]));
                give_ob(me, new("/kungfu/class/sky/obj/shenjiu"));
                give_ob(me, new("/kungfu/class/sky/obj/shenjiu"));
                give_ob(me, new("/kungfu/class/sky/obj/shenjiu"));
                give_ob(me, new("/kungfu/class/sky/obj/shenjiu"));
                give_ob(me, new("/kungfu/class/sky/obj/shenjiu"));
                give_ob(me, new("/kungfu/class/sky/obj/shenjiu"));
        //give_ob(me, new("/u/redl/npc/obj/ntb2"));
        ob = new("/clone/gift/jiuzhuan");
        ob->set_amount(50);
        drop_ob(me, ob);
        destruct(this_object());
        return 1;
}

void init()
{
        add_action("do_open","open"); 
}

