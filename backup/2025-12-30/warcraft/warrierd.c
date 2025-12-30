// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m烏龜[2;37;0m[2;37;0m", ({"help_nick"}));        
        set("gender", "男性");                
        set("long", "只比烏龜厲害那麼一點點[2;37;0m
它是達摩的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "warrierd");
        set("owner_name", "達摩");
        set_temp("owner", "warrierd");
        set_temp("owner_name", "達摩");
        ::setup();
}
