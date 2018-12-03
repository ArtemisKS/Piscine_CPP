/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CursesDisplay.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <akupriia@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:52:58 by akupriia          #+#    #+#             */
/*   Updated: 2018/12/03 08:20:07 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSESDISPLAY_HPP
#define CURSESDISPLAY_HPP

#include <IMonitorDisplay.hpp>
#include <Name.hpp>
#include <OS.hpp>
#include <Time.hpp>
#include <CPU.hpp>
#include <RAM.hpp>
#include <NetworkInfo.hpp>
#include <NetworkThro.hpp>
#include <Disks.hpp>
#include <Rest.hpp>
#include <Unicat.hpp>

class CursesDisplay : public IMonitorDisplay {

public:
	CursesDisplay( void );
	CursesDisplay( const CursesDisplay & );
	virtual ~CursesDisplay( void );

	CursesDisplay			&operator=( const CursesDisplay & );

	void					run( void );

protected:
	bool		isUser;
	bool		isOs;
	bool		isDate;
	bool		isCPUInfo;
	bool		isRAMInfo;
	bool		isNetInfo;
	bool		isNetInter;
	bool		isKatskiy;
	bool		isRest;
	bool		isDisks;

	std::vector<IMonitorModule*>	_modules;
	int								numCol;

	virtual void					refresh( void ) const;
	virtual void					init( void );

	virtual void					allocateAll( void );
	virtual void					deleteAll( void );
	virtual void					reAllocate( void );

	/* Module switchers */
	virtual void					switchName( void );
	virtual void					switchOSinfo( void );
	virtual void					switchTime( void );
	virtual void					switchCPU( void );
	virtual void					switchRAM( void );
	virtual void					switchNetworkThro( void );
	virtual void					switchNetworkInfo( void );
	virtual void					switchCat( void );
	virtual void					switchDisks( void );
	virtual void					switchRest( void );
	virtual void					switchCols( int );

};

#endif
