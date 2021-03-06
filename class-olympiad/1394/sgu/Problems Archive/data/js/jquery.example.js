/*
 * jQuery Example Plugin 1.3.2
 * Populate form inputs with example text that disappears on focus.
 *
 * e.g.
 *  $('input#name').example('Bob Smith');
 *  $('input[@title]').example(function() {
 *    return $(this).attr('title');
 *  });
 *  $('textarea#message').example('Type your message here', {
 *    class_name: 'example_text',
 *    hide_label: true
 *  });
 *
 * Copyright (c) Paul Mucur (http://mucur.name), 2007-2008.
 * Dual-licensed under the BSD (BSD-LICENSE.txt) and GPL (GPL-LICENSE.txt)
 * licenses.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */
(function(A){A.fn.example=function(D,C){var B=A.extend({},A.fn.example.defaults,C);var E=A.isFunction(D);if(!A.fn.example.bound_class_names[B.class_name]){A(window).unload(function(){A("."+B.class_name).val("")});A("form").submit(function(){A(this).find("."+B.class_name).val("")});A.fn.example.bound_class_names[B.class_name]=true}return this.each(function(){var G=A(this);if(G.val()==""){G.addClass(B.class_name);G.val(E?D.call(this):D)}if(B.hide_label){var F=A("label[@for="+G.attr("id")+"]");F.next("br").hide();F.hide()}G.focus(function(){if(A(this).is("."+B.class_name)){A(this).val("");A(this).removeClass(B.class_name)}});G.blur(function(){if(A(this).val()==""){A(this).addClass(B.class_name);A(this).val(E?D.call(this):D)}})})};A.fn.example.defaults={class_name:"example",hide_label:false};A.fn.example.bound_class_names=[]})(jQuery);