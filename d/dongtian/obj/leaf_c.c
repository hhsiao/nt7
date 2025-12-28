// This program is a part of NITAN MudLIB 
// redl 2015/3
#include <ansi.h>

void remove_effect(object me)
{
                if(!query_temp("apply/shade_vision", me)) return;
        tell_object(me, NOR "你的" + NOR HIC"仙隱"HIG"符葉" + NOR "效果快要消失了。\n" NOR);
}

void remove_effect2(object me)
{
                if(!query_temp("apply/shade_vision", me)) return;
        delete_temp("apply/shade_vision", me);
        message_vision(HIK "$N" HIK "的身形逐漸顯露出來，變的清晰可見。\n" NOR, me);
}

int do_remove_yinxian(object me) 
{
        int ra = 120 + random(10);
        call_out("remove_effect", ra - 5, me);
        call_out("remove_effect2", ra, me);
        return 1;
}


