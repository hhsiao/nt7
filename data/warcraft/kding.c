// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m玄龜[2;37;0m[2;37;0m", ({"kkdd"}));        
        set("gender", "男性");                
        set("long", "爽[2;37;0m
它是虐殺丁一的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "kding");
        set("owner_name", "虐殺丁一");
        set_temp("owner", "kding");
        set_temp("owner_name", "虐殺丁一");
        ::setup();
}
