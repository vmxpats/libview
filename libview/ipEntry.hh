/* *************************************************************************
 * Copyright (c) 2005 VMware, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 * *************************************************************************/


/*
 * ipEntry.hh --
 *
 *      Entry box for IP addresses. Checks for validity as users type.
 */


#ifndef LIBVIEW_IP_ENTRY_HH
#define LIBVIEW_IP_ENTRY_HH


#include <libview/fieldEntry.hh>


namespace view {


class IPEntry
   : public FieldEntry
{
public:
   enum Mode { IPV4, IPV6 };

   IPEntry(Mode = IPV4);

   void SetIP(const Glib::ustring& ip);
   Glib::ustring GetIP(void) const;

   void SetDotlessIP(unsigned long ip);
   unsigned long GetDotlessIP(void) const;

protected:
   virtual bool GetIsFieldValid(const Glib::ustring& str) const;
   virtual Glib::ustring GetAllowedFieldChars(size_t field) const;

   virtual bool on_focus_out_event(GdkEventFocus* event);

private:
   void NormalizeField(unsigned int field);

   Mode mMode;
};


} /* namespace view */


#endif /* LIBVIEW_IP_ENTRY_HH */
