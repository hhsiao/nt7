inherit ROOM;

#include <ansi.h>

void create()
{
        set("short", "七仙女臺");
        set("long",@LONG
這裡是一處高聳的平臺，傳說，七仙女常在這裡修煉仙法。放
眼望去，天際之處，一道彩虹劃空而過，七位美貌無比的仙女正翩
翩起舞，舞姿婀娜，如此美景，令人留戀忘返。
LONG);

        set("exits", ([
                "down"    : __DIR__"nanshanjiaoxia",
        ]));
        set("no_rideto", 1);         // 設置不能騎馬到其他地方
        set("no_flyto", 1);          // 設置不能從起來地方騎馬來這裡
        set("no_die", 1);            // 死亡後移動到扁鵲居
        set("penglai", 1);           // 表示在蓬萊島

        set("no_fight", 1);
        set("sleep_room", 1);
        
        set("region", "penglai");
        setup();
}

void init ()
{
        if( !query_temp("apply/xianshu-lingwei", this_player()) )
        {
                if( !query("penglai/go_quest/ok", this_player()) )
                {
                        this_player()->start_busy(3);
                        tell_object(this_player(), NOR + WHT "你到了此處，四周仙氣繚繞令你一時間難以辨別方向。\n" NOR);
                }
                else
                {
                        if (random(2))
                        {
                                this_player()->start_busy(1);
                                tell_object(this_player(), NOR + WHT "你到了此處，四周仙氣繚繞令你一時間難以辨別方向。\n" NOR);                
                        }
                }
        }
        
        if( !query("penglai/nanshan_quest/ok", this_player()) )
        {
                tell_object(this_player(), HIG "\n你被一陣仙氣卷下山去 ……！。\n" NOR);
                this_player()->move(__DIR__"nanshanjiaoxia");
        }
        else // 第一次七仙女臺增加容貌1點
        {
                if( !query("penglai/qixiannvtai_quest/ok", this_player()) && query("per", this_player())<30 )
                {
                        tell_object(this_player(), HIR "\n你看到了七仙女起舞的盛景，受益不淺。\n" NOR);
                        tell_object(this_player(), HIC "你的「容貌」提升了！\n\n" NOR);                        
                        CHANNEL_D->do_channel(this_object(), "rumor", "聽說" HIY + this_player()->name() + "(" + 
                                                             query("id", this_player())+")"HIM"在蓬萊仙島"
                                                             "看到了七仙女起舞的盛景，受益不淺。\n" NOR);   
                        addn("per", 1, this_player());
                        set("penglai/qixiannvtai_quest/ok", 1, this_player());
                        this_player()->save();
                }
        }
}
