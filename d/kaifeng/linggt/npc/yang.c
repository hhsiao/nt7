// This program is a part of NITAN MudLIB 
// redl 2012/12/1 
#include <ansi.h>

inherit NPC;

int ask_pan()
{
    object me = this_player();
    
                if ( time() - query("lgt/askpan", me) < 60 ){
                        tell_object(me, CYN"楊小邪怪眼一睨對你邪笑道：才問過又要來問，存心找削是不？\n"NOR); 
                        return -1; 
                }
    
    command("look " + query("id", me));
    command("whisper " + query("id", me) + " about 現在闖靈感塔需要有" + chinese_number(environment(this_object())->total_gold()) + "黃金的存款作為保證！");
    command("heihei " + query("id", me));
    set("lgt/askpan", time(), me);
    
        return 1;
}

void create()
{
        set_name(NOR "楊小邪" NOR, ({ "yang xiaoxie","yang","npc_yangxiaoxie" }) );
        set("title", NOR "通吃幫幫主" NOR);
        set("nickname", MAG "浪子不歸.飛刀無痕.邪功天下第一" NOR);
        set("gender", "男性");
        set("age", 17);
        set("long", NOR"他就是江湖上赫赫有名的通吃幫幫主通吃小霸王，看起來很是邪惡的樣子。\n"NOR);
        set("attitude", "peaceful");
        set("str", 30);
        set("con", 30);
        set("int", 30);
        set("dex", 30);
        set("per", 25);

        set("chat_chance", 1);
        set("chat_msg", ({
                                (: command("xixi npc_xiaoding") :),
                                (: command("grin npc_xiaoding") :),
                                (: command("ruffle npc_xiaoding") :),
        }) );

                set("level", 60);
        set("combat_exp", 10000000);

        set("inquiry", ([
                "盤口"   : (: ask_pan :),
                "靈感塔"     : "沒意思，我剛從上面跳下來，你也想登上去嗎？那得和我賭一把。\n"+NOR,
                "怎麼賭"     : "我和每個成功登塔的高手簽約，你如果失敗了得付我們若干黃金，只要你錢莊裡有存款。\n"+NOR,
                "簽約"     : "你想做歌星？唉，有足夠的存款直接上去就行了，你輸了我自己去取。\n"+NOR,
                "小丁"     : "不就在我旁邊嗎..你都知道了？呃，是的，其實我們都不夠邪惡...\n"+NOR,
        ]));

        setup();

}




