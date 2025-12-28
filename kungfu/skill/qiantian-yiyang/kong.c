//kong for stop liumai-shenjian
//COOL@SJ

#include <ansi.h>

inherit F_CLEAN_UP;

int exert(object me)
{
        if(!me->query_temp("start_6mai")) 
                return notify_fail("你現在沒有運用六脈神劍。\n");     
        message_vision(HIG"$N屈指一收，手指垂下，體內鼓盪的六脈真氣緩緩納入丹田。\n\n"NOR,  
                      me);
        me->delete_temp("start_6mai");
        
        me->start_busy(1);
        
        return 1;
}

string exert_name(){ return HIG"空"NOR; }

int help(object me)
{
        write(HIG"\n乾天一陽功之「空」："NOR"\n\n");
        write(@HELP
        要求：  必須運用六脈神劍後。
        
HELP
        );
        return 1;
}
