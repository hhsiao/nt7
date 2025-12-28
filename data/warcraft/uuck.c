// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m太古蒼龍[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "太古蒼龍，盤古開天后第一隻神獸，乃萬物之源[2;37;0m
它是上官春捲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "uuck");
        set("owner_name", "上官春捲");
        set_temp("owner", "uuck");
        set_temp("owner_name", "上官春捲");
        ::setup();
}
