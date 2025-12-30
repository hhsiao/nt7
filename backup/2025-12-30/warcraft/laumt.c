// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m剪刀獸[2;37;0m[2;37;0m", ({"laumtbb"}));        
        set("gender", "男性");                
        set("long", "我就是大怪誕[2;37;0m
它是不辣魔特的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "laumt");
        set("owner_name", "不辣魔特");
        set_temp("owner", "laumt");
        set_temp("owner_name", "不辣魔特");
        ::setup();
}
