/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        pool.c
 * @ingroup     asio
 *
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "pool.h"
#include "aico.h"
#include "impl/impl.h"
#include "../memory/memory.h"
#include "../platform/platform.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
tb_pointer_t tb_aico_pool_malloc_(tb_aico_ref_t aico, tb_size_t size __tb_debug_decl__)
{
    // check 
    tb_aico_impl_t* impl = (tb_aico_impl_t*)aico;
    tb_assert_and_check_return_val(impl, tb_null);

    // init pool
    if (!impl->pool) impl->pool = tb_pool_init(TB_POOL_GROW_MICRO, 0);
    tb_assert_and_check_return_val(impl->pool, tb_null);

    // malloc
    return tb_pool_malloc_(impl->pool, size __tb_debug_args__);
}
tb_pointer_t tb_aico_pool_malloc0_(tb_aico_ref_t aico, tb_size_t size __tb_debug_decl__)
{
    // check 
    tb_aico_impl_t* impl = (tb_aico_impl_t*)aico;
    tb_assert_and_check_return_val(impl, tb_null);

    // init pool
    if (!impl->pool) impl->pool = tb_pool_init(TB_POOL_GROW_MICRO, 0);
    tb_assert_and_check_return_val(impl->pool, tb_null);

    // malloc0
    return tb_pool_malloc0_(impl->pool, size __tb_debug_args__);
}
tb_pointer_t tb_aico_pool_nalloc_(tb_aico_ref_t aico, tb_size_t item, tb_size_t size __tb_debug_decl__)
{
    // check 
    tb_aico_impl_t* impl = (tb_aico_impl_t*)aico;
    tb_assert_and_check_return_val(impl, tb_null);

    // init pool
    if (!impl->pool) impl->pool = tb_pool_init(TB_POOL_GROW_MICRO, 0);
    tb_assert_and_check_return_val(impl->pool, tb_null);

    // nalloc
    return tb_pool_nalloc_(impl->pool, item, size __tb_debug_args__);
}
tb_pointer_t tb_aico_pool_nalloc0_(tb_aico_ref_t aico, tb_size_t item, tb_size_t size __tb_debug_decl__)
{
    // check 
    tb_aico_impl_t* impl = (tb_aico_impl_t*)aico;
    tb_assert_and_check_return_val(impl, tb_null);

    // init pool
    if (!impl->pool) impl->pool = tb_pool_init(TB_POOL_GROW_MICRO, 0);
    tb_assert_and_check_return_val(impl->pool, tb_null);

    // nalloc0
    return tb_pool_nalloc0_(impl->pool, item, size __tb_debug_args__);
}
tb_pointer_t tb_aico_pool_ralloc_(tb_aico_ref_t aico, tb_pointer_t data, tb_size_t size __tb_debug_decl__)
{
    // check 
    tb_aico_impl_t* impl = (tb_aico_impl_t*)aico;
    tb_assert_and_check_return_val(impl, tb_null);

    // init pool
    if (!impl->pool) impl->pool = tb_pool_init(TB_POOL_GROW_MICRO, 0);
    tb_assert_and_check_return_val(impl->pool, tb_null);

    // ralloc
    return tb_pool_ralloc_(impl->pool, data, size __tb_debug_args__);
}
tb_bool_t tb_aico_pool_free_(tb_aico_ref_t aico, tb_pointer_t data __tb_debug_decl__)
{
    // check 
    tb_aico_impl_t* impl = (tb_aico_impl_t*)aico;
    tb_assert_and_check_return_val(impl && impl->pool, tb_false);

    // free
    return tb_pool_free_(impl->pool, data __tb_debug_args__);
}

