#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg) {
    if(me->is_busy() )
        return notify_fail("你正忙著呢。\n");

    if(me->is_fighting() )
        return notify_fail("你現在正在戰鬥！\n");

    if(me->is_ghost() )
        return notify_fail("等你還了陽再說吧。\n");

    if(me->is_in_prison() )
        return notify_fail("你正在做牢呢。\n");

    if(query("doing", me) )
        return notify_fail("你還想幹什麼？！\n");

    if (base_name(environment(me)) == "/d/city/kedian4")
        return notify_fail("你已經在聊天室了。\n");

    if(query("no_magic", environment(me)) )
        return notify_fail("你發現從這裡不能進入聊天室！\n");

    if(query_temp("warquest/party", me) )
        return notify_fail("你還想在戰爭中使用？！\n");

    if(sscanf(base_name(environment(me)), "/d/register/%*s") )
        return notify_fail("你還沒有出生呢，不能施展！\n");

    if(sscanf(base_name(environment(me)), "/d/newbie/%*s") )
        return notify_fail("你在古村中，不能施展！\n");

    message("vision", me->name() + "舉起右手在面前極速畫了一個圓，竟劃破了面前的"
        "空間，\n只見圓內的空間真空將" + me->name() + "給吸了進去。\n",
        environment(me), ({me}));

    tell_object(me, "你從聊天室的某個角落空間裂縫中鑽出。\n");
    me->move("/d/city/kedian4");
    MYGIFT_D->check_mygift(me, "newbie_mygift/chatroom");

    message("vision", me->name() + "從聊天室的某個角落空間裂縫中鑽出。\n",
        environment(me), ({me}));

    return 1;
}
