/*
 * uriparser - RFC 3986 URI parsing library
 *
 * Copyright (C) 2007, Weijia Song <songweijia@gmail.com>
 * Copyright (C) 2007, Sebastian Pipping <webmaster@hartwork.org>
 * All rights reserved.
 *
 * Redistribution  and use in source and binary forms, with or without
 * modification,  are permitted provided that the following conditions
 * are met:
 *
 *     * Redistributions   of  source  code  must  retain  the   above
 *       copyright  notice, this list of conditions and the  following
 *       disclaimer.
 *
 *     * Redistributions  in  binary  form must  reproduce  the  above
 *       copyright  notice, this list of conditions and the  following
 *       disclaimer   in  the  documentation  and/or  other  materials
 *       provided with the distribution.
 *
 *     * Neither  the name of the <ORGANIZATION> nor the names of  its
 *       contributors  may  be  used to endorse  or  promote  products
 *       derived  from  this software without specific  prior  written
 *       permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT  NOT
 * LIMITED  TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS
 * FOR  A  PARTICULAR  PURPOSE ARE DISCLAIMED. IN NO EVENT  SHALL  THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL,    SPECIAL,   EXEMPLARY,   OR   CONSEQUENTIAL   DAMAGES
 * (INCLUDING,  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT  LIABILITY,  OR  TORT (INCLUDING  NEGLIGENCE  OR  OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file UriConfig.h
 * Adjusts the internal configuration after processing external definitions.
 */

#ifndef URI_CONFIG_H
#define URI_CONFIG_H 1



/* Deny external overriding */
#undef URI_ENABLE_ANSI      /* Internal for !URI_NO_ANSI */
#undef URI_ENABLE_UNICODE   /* Internal for !URI_NO_UNICODE */
#undef URI_ENABLE_LEGACY    /* Internal for !URI_NO_LEGACY */



#ifdef URI_NO_ANSI
# ifndef URI_NO_LEGACY
/* Deny legacy without ANSI */
#  error URI_NO_ANSI cannot go without URI_NO_LEGACY.
# else
#  ifdef URI_NO_UNICODE
/* No encoding at all */
#   error URI_NO_ANSI and URI_NO_UNICODE cannot go together.
#  else
/* Unicode only */
#   define URI_ENABLE_UNICODE   1
#  endif
# endif
#else
# ifdef URI_NO_UNICODE
/* ANSI only */
#  define URI_ENABLE_ANSI       1
# else
/* Both ANSI and Unicode */
#  define URI_ENABLE_ANSI       1
#  define URI_ENABLE_UNICODE    1
# endif
#endif

#ifndef URI_NO_LEGACY
# define URI_ENABLE_LEGACY      1
#endif



#endif /* URI_CONFIG_H */
