// This program is a part of NT MudLIB

#include <ansi.h>

inherit F_CLEAN_UP;

#include <equipment.h>

int main(object me, string arg) {
    int status;
    object ob;
    string part;

    if(!arg )
    {
        string msg;
        object *equipments = me->query_equipment_objects();

        if(!sizeof(equipments) )
            return notify_fail(pnoun(2, me) + "目前身上沒有任何裝備。\n");

        msg = pnoun(2, me) + "目前身上的裝備如下：\n";

        foreach(ob in me->query_equipment_objects())
            msg += "．"HIW"["NOR + me->query_equipping_part(ob) + HIW"] "+ob->query_idname() + "\n"NOR;

        tell(me, msg + "\n");
        return 1;
    }

    //忙碌中不能下指令
    if(me->is_busy() )
    {
        tell(me, BUSY_MESSAGE);
        me->show_prompt();
        return 1;
    }

    if(arg == "all" )
    {
        foreach(ob in all_inventory(me))
        {
            part = me->query_equipping_part(ob);
            if(me->unequip(ob, ref status) )
                msg("$ME卸除了裝備在「"+part + "」部位上的"+ob->query_idname() + "。\n", me, 0, 1);
        }

        return 1;
    }

    if(!objectp(ob = present(arg, me)) )
        return notify_fail(pnoun(2, me) + "的身上並沒有 "+arg + " 這個物品。\n");

    part = me->query_equipping_part(ob);
    if(!me->unequip(ob, ref status) )
    {
        switch(status)
        {
            // 1: 並無裝備此物件
            // 2: 無法解除此項裝備

            // should not happen
        case 1: return notify_fail(pnoun(2, me) + "並未裝備"+ob->query_idname() + "。\n"); break;
        case 2: return notify_fail(pnoun(2, me) + "無法卸除這項裝備。\n"); break;
        }
    }
    else
        msg("$ME卸除了裝備在「"+part + "」部位上的"+ob->query_idname() + "。\n", me, ob, 1);
    return 1;
}

int help(object me) {
    string help = @HELP
    卸除裝備物品的指令，無論是武器、衣物、座騎、裝飾品、團體武裝都
是利用此指令進行卸除裝備的動作。

unequip '物品'           卸除裝備某項物品
unequip all              卸除裝備所有物品

HELP;
    write(help);
    return 1;
}
