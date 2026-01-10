// This program is a part of NITAN MudLIB
// redl 2013/4/1
#include <ansi.h>

inherit ITEM;

int halt_diging(object me)
{
        message_vision(YEL + "$N放下"+query("name")+ NOR + YEL + "擦了擦汗。\n" + NOR,  me);
        delete_temp("toucai", me);
        me->set_short_desc(0);
        me->stop_busy();
        me->start_busy(2);
        return 1;
}

int diging(object me)
{
        int stage, rnd, exp;
        object tool = query_temp("toucai_tool", me);

        if (!objectp(tool) || environment(tool) != me)
        {
                        tell_object(me, "咦...你的鋤頭呢？\n");
                delete_temp("toucai", me);
                me->set_short_desc(0);
            me->stop_busy();
            me->start_busy(6);
                return 1;
        }

        if (query("nj", tool) < 1 ){
                        message_vision(NOR + "$N手裡的"+query("name")+ NOR + "咔嚓一聲散架了。\n" + NOR,  me);
                me->set_short_desc(0);
            me->stop_busy();
                me->start_busy(2);
                        destruct(this_object());
                return 1;
        }

        switch(stage=query_temp("toucai", me) )
        {
        case 1:
        case 2:
        case 3:
        case 4:
                if (random(3))//黃金鋤在此加速
                {
                        tell_object(me, "你輕輕地刨翻著菜地。\n");
                        break;
                }

                tell_object(me, "你挖掘動作逐漸放慢了..\n");
                stage++;
                break;
        case 5:
                        tell_object(me, "你提鋤頭時似乎有些吃力...\n");
                stage++;
                break;
        case 6:
                        rnd = random(1000);
                        exp = 280 + random(100);
                if (rnd<12){//魯智深出現
                        tell_object(me, CYN + "你面前突然出現一個胖大和尚暴喝道：哪裡來的潑皮，敢來灑家地裡偷菜！\n" +
                                                                  "說完一個醋缽大小的拳頭撲面飛至，你慌忙地舉起小鋤頭一擱架，“咔嚓”一聲\n" +
                                                                  "你的鋤頭快斷了，鼻子也被打破了...\n" + NOR);
                        set("nj", 0, tool);
                                        set_temp("block_msg/all",1 ,me);
                        message_vision(YEL + "一個黑影暴雷似的一聲大喝，$N還沒來得及反應，臉上就重重捱了一拳。\n" + NOR, me);
                        delete_temp("block_msg/all", me);
                        //me->unconcious();//給被偷搶的機會

                                delete_temp("toucai", me);
                                me->set_short_desc(0);
                                me->stop_busy();
                                me->start_busy(2);
                                return 1;
                }
                else if (rnd<111){//金元寶=百兩黃金
                        message_vision(YEL + "$N一鋤頭下去“咔嗒”一聲，似乎挖到了什麼，\n$N狂喜之下刨出一塊金閃閃的硬物揣到懷裡。\n" + NOR, me);
                        new("/clone/money/yuanbao")->move(me);
                        if (query("combat_exp", me)>1000000 && query("combat_exp", me)<5000000) GIFT_D->work_bonus(me, ([ "exp" : exp, "pot" : exp / 4 ]));
                }
                else if (rnd<133){//血菩提、舍利、昊天果，都為最低級並有服用CD之物，正好避免多開大米去餵養主id
                        message_vision(YEL + "$N一鋤頭下去“咔嗒”一聲，似乎挖到了什麼，\n$N驚喜之下刨出一塊不知名的果實揣到懷裡。\n" + NOR, me);
                        rnd = random(3);
                        if (rnd==0) new("/clone/fam/pill/puti1")->move(me);
                                else if (rnd==1) new("/clone/fam/pill/sheli1")->move(me);
                                else new("/clone/fam/pill/linghui1")->move(me);
                        exp /= 3;
                        if (query("combat_exp", me)>1000000 && query("combat_exp", me)<5000000) GIFT_D->work_bonus(me, ([ "exp" : exp, "pot" : exp / 4 ]));
                }
                else {
                        message_vision(YEL + "$N一鋤頭下去“噗哧”一聲，挖到一顆粘糞的爛白菜，\n$N悻悻地把爛白菜扔到一邊，唸叨：“鋤禾日當午，偷情真幸苦”。\n" + NOR, me);
                        exp /= 6;
                        if (query("combat_exp", me)>1000000 && query("combat_exp", me)<5000000) GIFT_D->work_bonus(me, ([ "exp" : exp, "pot" : exp / 4 ]));
                }

                //stage = 1;
                //me->set_short_desc(0);
                //break;

                                halt_diging(me);
                                return 1;
                default:
                    me->set_short_desc(0);
                    me->stop_busy();
                        me->start_busy(2);
                                return 1;
        }

        set_temp("toucai", stage, me);
        return 1;
}

varargs int move(mixed dest, int raw)
{
        object me;

        if (me = query_temp("owner"))
                me->interrupt_me();

        return ::move(dest, raw);
}


int do_dig()//string arg)
{
        object *obs;
        object where;
        object me = this_player();

//              if (! arg || arg != "cai"){
//                      tell_object(me, "你要挖什麼？\n");
//                      return 1;
//              }

        if (me->is_busy() || me->is_fighting()){
                        tell_object(me, "你還是忙完手頭上的事情再說吧。\n");
                        return 1;
                }
  if ( !interactive(this_player()) ) return 1;

//         if (query("combat_exp", me)>5000000){
//              tell_object(me, "你實戰經驗大於五百萬了，別再做這種丟臉的事了。\n");
//                      return 1;
//              }
//
//         if (query("combat_exp", me)<1000000){
//              tell_object(me, "你實戰經驗還不足一百萬，放棄這想法吧。\n");
//                      return 1;
//              }

                where = environment(me);
/*
                if (!sscanf(base_name(where), "/d/kaifeng/caidi%*s")){
                        tell_object(me, "這裡不是開封大相國寺的菜地吧？\n");
                        return 1;
                }
*/
                if (strsrch(query("short", where), "菜地") == -1) {
                        tell_object(me, "這裡不是菜地吧？\n");
                        return 1;
                }

        obs = filter_array(all_inventory(where),
                           (: interactive($1) &&
                             $1 != $(me) &&
                             query_temp("toucai", $1) :));

        if (sizeof(obs) > 10)
        {
                 tell_object(me, "這裡已經有" + sizeof(obs) + "個人在偷菜了，你等等吧。\n");
                 return 1;
        }

                if (query("nj") < 1) {
                        message_vision(NOR + "$N手裡的"+query("name")+ NOR + "咔嚓一聲散架了。\n" + NOR,  me);
                        destruct(this_object());
                        return 1;
                } else addn("nj", -1);

        message_vision(YEL + "$N鬼鬼祟祟地摸出一把小鋤看了看周圍，飛速地蹲下來挖挖挖..\n" + NOR, me);
        set_temp("toucai", 1, me);
        set_temp("toucai_tool", this_object(), me);
        me->start_busy((: call_other, __FILE__, "diging" :),
                       (: call_other, __FILE__, "halt_diging" :));
                me->set_short_desc("正在偷菜。");
        return 1;
}



void init()
{
        if (interactive(this_player()) &&
            environment() == this_player())
        {
                add_action("do_dig", "toucai");
                add_action("do_dig", "wacai");
        }
}

void create()
{
        set_name(NOR "小鋤頭" NOR, ({ "chu tou", "chu" }));
        /*if (clonep())
                set_default_object(__FILE__);
        else
        {*/
                set("unit", "把");
                set("long", "這是一把能在菜地裡使用的小鋤頭，\n上面寫著“開封大相國寺.制”，指令(toucai)或者(wacai)。\n");//不和emote wa重複cmd dig重複
                set("value", 2500);
                set("weight", 50000000);
                set("nj", 100);
                set("no_store", "這樣東西不能放在那兒。\n");
                set("no_steal", "這樣東西不能離開那兒。\n");
                set("no_beg", "這樣東西不能離開那兒。\n");
                                set("set_data", 1);
                                set("auto_load", 1);
                        //}

        setup();
}
