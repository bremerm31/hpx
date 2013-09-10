// Copyright (c) 2007-2013 Hartmut Kaiser
// Copyright (c) 2012-2013 Thomas Heller
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// This file has been automatically generated using the Boost.Wave tool.
// Do not edit manually.


        template <
            typename Functor
          , typename R
           
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R()
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R()
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R()
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f )
            {
                return invoke_(f , typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()();
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))();
            }
        };
        template <
            typename Functor
           
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void()
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void()
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void()
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f )
            {
                invoke_(f , typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()();
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))();
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0)
            {
                return invoke_(f , a0, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0);
            }
        };
        template <
            typename Functor
          , typename A0
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0)
            {
                invoke_(f , a0, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1)
            {
                return invoke_(f , a0 , a1, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1)
            {
                invoke_(f , a0 , a1, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2)
            {
                return invoke_(f , a0 , a1 , a2, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2)
            {
                invoke_(f , a0 , a1 , a2, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3)
            {
                return invoke_(f , a0 , a1 , a2 , a3, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3)
            {
                invoke_(f , a0 , a1 , a2 , a3, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11);
            }
        };
        template <
            typename Functor
          , typename R
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , R(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
                    >::template get<IArchive, OArchive>();
            }
            BOOST_FORCEINLINE static R
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12)
            {
                return invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12, typename boost::is_reference_wrapper<Functor>::type());
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12, boost::mpl::true_)
            {
                return (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            }
            BOOST_FORCEINLINE static R
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12, boost::mpl::false_)
            {
                return (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            }
        };
        template <
            typename Functor
          , typename A0 , typename A1 , typename A2 , typename A3 , typename A4 , typename A5 , typename A6 , typename A7 , typename A8 , typename A9 , typename A10 , typename A11 , typename A12
          , typename IArchive
          , typename OArchive
        >
        struct type<
            Functor
          , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
          , IArchive
          , OArchive
        >
            : type_base<Functor>
        {
            static vtable_ptr_base<
                void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
              , IArchive
              , OArchive
            > *get_ptr()
            {
                return
                    get_table<
                        Functor
                      , void(A0 , A1 , A2 , A3 , A4 , A5 , A6 , A7 , A8 , A9 , A10 , A11 , A12)
                    >::template get<IArchive, OArchive>();
            }
            static
            BOOST_FORCEINLINE void
            invoke(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12)
            {
                invoke_(f , a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12, typename boost::is_reference_wrapper<Functor>::type());
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12, boost::mpl::true_)
            {
                (**reinterpret_cast<Functor**>(f)).get()(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            }
            static
            BOOST_FORCEINLINE void
            invoke_(void ** f , A0 a0 , A1 a1 , A2 a2 , A3 a3 , A4 a4 , A5 a5 , A6 a6 , A7 a7 , A8 a8 , A9 a9 , A10 a10 , A11 a11 , A12 a12, boost::mpl::false_)
            {
                (**reinterpret_cast<Functor**>(f))(a0 , a1 , a2 , a3 , a4 , a5 , a6 , a7 , a8 , a9 , a10 , a11 , a12);
            }
        };
