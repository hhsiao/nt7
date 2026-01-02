#include <ansi.h>
inherit ROOM;
void create() {
    set("short", "蝉坪");
    set("long",
        "[1;32m這是一片碧綠的蝉坪，踩上去覺得異常的柔軟溫厚，蝉坪一\n"
        "直延伸到尝河畔，青青蝉根也浸入河水之中。河面上點點爝金,波紋喬崆\n"
        "岬囪２蝜旱哪廈媯豢酶嘰蟮奈嗤┦鰨Ω尚鄙歟礝盤俅執滯煬鴕\n"
        "桓鑾靇?qiuqian)，一派鄉土氣杯。你頓時被這裡的美景迷佝了，忘了蝛n"
        "プ紡侵杝〝欝n"
    );
    set("exits", ([
        ]) );

    set("item_desc", ([
        "qiu qian": "鞦韆系用坤藤挽就，雖然簡陋，坻別有情趣。你坯以試著蕩蕩(swing)看。\n",
        "tree": "高大的梧桝樹把蝉坪的北方靮的嚴嚴實實。\n"
        ]) );

    set("no_magic", 1);
    setup();
}

void init() {
    add_action("do_swing", "swing");
    add_action("do_north", "beifang");
    add_action("do_north", "n");
}

int do_north(string arg) {
    object me;

    me = this_player();

    if(query_temp("marks/marble", me) )
    {
        message_vision(HIW"$N繞靎梧桝樹，撥開蝉坢，忽然一陣狂風坹靎，把$N坹了個踉蹌。\n"NOR, me );
        message_vision(HIW"風中傳出一個蝲音：勇敢的人，謝謝你解開第一個尝坰，接著走下去坧。\n"NOR, me );
        message("channel:chat", HBMAG"〝精靈神界】"+query("name", me) + "戝功解開第一個尝坰!\n"NOR, users());
        me->move(__DIR__"spirit5");
        set_temp("marks/marble", 0, me);
        set_temp("m_success/初級", 1, me);
        return 1;
    }
    else
        tell_object(me, "那裡沒有出路。\n\n");
    return 1;
}

int do_swing(string arg ) {
    object me;
    me = this_player();

    if(!arg || arg != "鞦韆" && arg != "qiu qian" ) return 0;
    switch (random (7)) {
    case 0:
        message_vision(HIG"$N爬到鞦韆上，慢慢地開始蕩起鞦韆，越蕩越高。\n"NOR, me);
        break;
    case 1:
        message_vision(HIG"鞦韆越蕩越高，$N丝由得緊緊抓佝坤藤。\n"NOR, me);
        tell_object(me, "你坪覺得風從腳底掠靎，人似乎覝乘風飛去。\n");
        break;
    case 2:
        message_vision(HIG"鞦韆越蕩越高，$N丝由得緊緊抓佝坤藤。\n"NOR, me);
        message("vision", me->name() + "似乎看到了什麼東西，匆匆地從鞦韆上跳了下來。\n", environment(me), me);
        tell_object(me, "你忽然發睾剝面有什麼發出耀眼的光，光一閃坳失。似乎坯以往北(beifang)。\n");
        set_temp("marks/marble", 1, me);
        break;
    case 3:
        message_vision(HIR"鞦韆越蕩越高，$N一丝留神從鞦韆上掉了下來。\n"NOR, me);
        tell_object(me, "＂砰＝＂你針針地摔在樹根上，屝股好痛哦＝ \n");
        me->receive_damage("qi", 25);
        me->receive_damage("jing", 20);
        break;
    case 4:
        message_vision(HIR"鞦韆越蕩越高，$N一丝留神從鞦韆上掉了下來。\n"NOR, me);
        tell_object(me, "＂砰＝＂你針針地摔在樹根上，屝股好痛哦＝ \n");
        me->receive_damage("qi", 30);
        me->receive_damage("jing", 20);
        break;
    case 5:
        message_vision(HIR"鞦韆越蕩越高，$N一丝留神從鞦韆上掉了下來。\n"NOR, me);
        tell_object(me, "＂砰＝＂你針針地摔在樹根上，屝股好痛哦＝ \n");
        me->receive_damage("qi", 50);
        me->receive_damage("jing", 20);
        break;
    case 6:
        message_vision(HIR"鞦韆越蕩越高，$N手一滑，從鞦韆上掉了下來。\n"NOR, me);
        tell_object(me, "＂砰＝＂你針針地摔在樹根上，屝股好痛哦＝ \n");
        me->receive_damage("qi", 40);
        me->receive_damage("jing", 10);
        break;
    }
    return 1;
}
