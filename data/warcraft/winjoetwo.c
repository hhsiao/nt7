// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m南[1;37m海[1;33m狂[1;32m尼[2;37;0m[2;37;0m", ({"knock"}));        
        set("gender", "男性");                
        set("long", "一條老青龍，拜入南海老尼姑門下，男的拜尼姑，悲哀啊！[2;37;0m
它是邵四豐的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "winjoetwo");
        set("owner_name", "邵四豐");
        set_temp("owner", "winjoetwo");
        set_temp("owner_name", "邵四豐");
        ::setup();
}
