// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[37m月之艾西莉亞[2;37;0m[2;37;0m", ({"wux"}));        
        set("gender", "女性");                
        set("long", "月之艾西莉亞[2;37;0m
它是段小虛的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wuxu");
        set("owner_name", "段小虛");
        set_temp("owner", "wuxu");
        set_temp("owner_name", "段小虛");
        ::setup();
}
