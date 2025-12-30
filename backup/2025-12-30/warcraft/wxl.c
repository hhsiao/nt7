// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m母[1;37m老虎[2;37;0m[2;37;0m", ({"mlh"}));        
        set("gender", "女性");                
        set("long", "母老虎[2;37;0m
它是萬全之策的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wxl");
        set("owner_name", "萬全之策");
        set_temp("owner", "wxl");
        set_temp("owner_name", "萬全之策");
        ::setup();
}
