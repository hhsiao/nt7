// This program is a part of NITAN MudLIB 
// redl 2013/5
// 非戰時用品，不用冷卻

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIC"芳"HIY"華"HIW"木" NOR, ({"mu"}));
                set("nj", 30);//60 nt，2nt解毒full一次
                set("longx",  
HIK 
"(                          芳華獸的傳說\n"
"    芳華獸皆為雄獸，性安，獨居，身形與凡人無異，尤善植奇花異草珍藥，\n"
"濯然而名，花同華，故名芳華獸。\n"
"    芳華獸，少言，神色多寂寥。膚白如凝脂，終年異香，眉眼下有硃砂痣。\n"
"淚痣顏色愈淺愈年少，直至殷紅、暗紅、墨黑，芳華獸亡之。\n"
"    獸亡後自浴火海，化為一截枯木，曰芳華木。此木乃芳華獸之精魄，可解\n"
"萬世之毒。如將木埋入土中，將藥草、花瓣碾碎加之晨曦露滴哺之，一月後枯\n"
"木紅而似火，質地如玉；再二月，顏色褪淡，木上長出四肢；再三月，木出五\n"
"官，似成年人，既而木質變柔，白而無瑕；又四月，木根斷，芳華獸出世。若\n"
"獸成形之十月期，以摯愛之血為引每日濯之，乃續魂，幼獸尚能保留前世記憶。\n"
"出世後的幼獸不通人語，食花蜜、花瓣及少量藥草為食，但成長極其快，不出\n"
"半歲身形便與人類小孩無異，此時便言語流暢，極其聰慧，此後十天便如人類\n"
"小孩一年，直至成年。\n"
"    芳華獸乃至情之物，若成年獸不墮紅塵，心如明鏡，可長命乃至修仙，動\n"
"情者便如荒草，歲歲枯榮，浴入火海，反覆輪迴。若被情傷，十日將如凡人一\n"
"年，直至墮入輪迴化為枯木，情傷愈重，木質色澤愈黑，化毒藥性愈強。\n"
"    芳華絕色，世間難尋，此獸乃至情至性之物，終其一生為情所困，終逃不\n"
"脫情殤之劫，成正果者少之又少。)\n"
NOR);
                //set("base_unit", "根");
                //set("base_value", 150000000);
                //set("base_weight", 800);
                set("value", 1);
                set("weight", 800000);
                set("unit", "根");
                //set("no_store", 1); 
                set("no_steal", 1); 
                set("no_beg", 1); 
                set("set_data", 1);  
                set("auto_load", 1);  
        setup();
}

string long()
{
        return HIG "這是一根芳華獸的遺骨所化的神木 - 耐久度："+ HIC + query("nj") + HIG + 
                        "\n聞之(smell mu)  可解萬毒除虛弱醫目盲原地復活，\n食之(eat mu)    可以直接到最美好的十八歲年齡(必須完整耐久度)。\n" NOR + query("longx");
}

void init()
{
        add_action("do_smell", "smell");
        add_action("do_eat", "eat");
}

int do_smell(string arg)
{
    mapping my;
        object me = this_player();
        
        if (! arg || arg != "mu") {
                tell_object(me, "你要聞什麼東西？\n");
                return 1;
        }
        if (me->is_busy()) {
                tell_object(me, "你先忙完手裡的事再說吧！\n");
                return 1;
        }
     if (query_temp("durg_time/mu", me) > time()) {
         tell_object(me, "你這麼頻繁地聞以為是吸毒啊？\n"); 
         return 1;
     }

/*
        if (me->is_fighting()) {
                tell_object(me, "你正在打架沒空去聞木頭！\n");
                return 1;
        }
*/
        
        me->start_busy(1);
        delete_temp("block_msg/all", me);
        my = me->query_entire_dbase();
        my["jing"]   = my["eff_jing"]   = my["max_jing"]; 
        my["jingli"] = my["eff_jingli"] = my["max_jingli"]; 
        my["qi"]     = my["eff_qi"]     = my["max_qi"]; 
        my["neili"]  = my["max_neili"];
        me->clear_condition();
        me->clear_weak();
              if( query_temp("block_msg/all", me) ) { 
                              tell_object(me, HIR "你終於抹掉了眼前的鮮血，能看見了。\n" NOR); 
                              delete_temp("block_msg/all", me); 
              } 
        //me->full_self();
     set_temp("durg_time/mu", time() + 60, me);

        message_vision(YEL + "$N取出一截"+ query("name") + YEL +"放在鼻端嗅了嗅，旋即精神大振。\n" + NOR, me); 
        addn("nj", -1);
        if (query("nj") < 1) {
                message_vision(NOR + "$N手裡的"+ query("name") + NOR +"微顫，化作恢恢消散了。\n" + NOR, me); 
                destruct(this_object());
        }
        return 1;
}


int do_eat(string arg)
{
        object me = this_player();
        
        if (! arg || arg != "mu") {
                //tell_object(me, "你要吃什麼東西？\n");
                return 0;
        }
        if (me->is_busy()) {
                tell_object(me, "你先忙完手裡的事再說吧！\n");
                return 1;
        }
        if (me->is_fighting()) {
                tell_object(me, "你正在打架沒空去吃木頭！\n");
                return 1;
        }
        if (query("nj") != 30) {
                tell_object(me, "你手裡這根木頭不完整了！\n");
                return 1;
        }
        
        me->start_busy(1);
        set("age", 18, me);
        set("mud_age", (18 - 11) * 518400, me);
        message_vision(YEL + "$N拿出一截"+ query("name") + YEL +"捏碎成黑粉，仰頭吞了下去。\n" + NOR +
                                                 "$N的全身骨骼咔咔作響，皮膚也不斷扭曲，片刻之後身形一頓定了下來，顯得好年輕啊~~~\n" + NOR, me); 
        message_vision(NOR + "$N手裡的"+ query("name") + NOR +"微顫，化作恢恢消散了。\n" + NOR, me); 
        destruct(this_object());
        return 1;
}


